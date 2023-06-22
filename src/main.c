/*Tyler Taormina*/
#include "stm32f30x.h"
#include "stm32f3_discovery.h"

int
main(void) 
{
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOE | RCC_AHBPeriph_GPIOA, ENABLE);

    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Pin  = GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 |  GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15; 
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOE, &GPIO_InitStruct);

    GPIO_InitTypeDef GPIO_InitStructA;
    GPIO_InitStructA.GPIO_Pin  = GPIO_Pin_0; 
    GPIO_InitStructA.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructA.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_InitStructA.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructA.GPIO_PuPd = GPIO_PuPd_DOWN;
    GPIO_Init(GPIOE, &GPIO_InitStructA);


    while(1)
    {
        if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0))
        {
            GPIO_SetBits(GPIOE, GPIO_Pin_12 | GPIO_Pin_9); } else 
        {
            GPIO_ResetBits(GPIOE, GPIO_Pin_12 | GPIO_Pin_9);
            GPIO_SetBits(GPIOE, GPIO_Pin_10);
            for (long i=0; i < SystemCoreClock/30; i++) {__NOP(); }
            GPIO_ResetBits(GPIOE, GPIO_Pin_10);
            for (long i=0; i < SystemCoreClock/30; i++) {__NOP(); }
        }
 
        /*
        GPIO_SetBits(GPIOE, GPIO_Pin_12);
        for (long i=0; i < SystemCoreClock/30; i++) {__NOP(); }
        GPIO_ResetBits(GPIOE, GPIO_Pin_12);
        for (long i=0; i < SystemCoreClock/30; i++) {__NOP(); }
        */
    }
    return 0;
}

