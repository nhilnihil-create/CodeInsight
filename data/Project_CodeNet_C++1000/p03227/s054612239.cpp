/*
 * main.c
 *
 *  Created on: 2019/04/20
 *      Author: family
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    char S[4];
    int len = 0;
    scanf("%s", S);
    len = strlen(S);
    if(len==2) {
        printf("%s\n", S);
    } else {
        printf("%c%c%c\n", S[2],S[1],S[0]);
    }
    return 0;
}
