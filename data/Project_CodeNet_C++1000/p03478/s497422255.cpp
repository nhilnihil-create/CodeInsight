#include <stdio.h>


int main (){

    int n,a,b,sumDig,sumAll = 0,temp ,digits;
    int flag = 0;
    scanf("%d %d %d", &n, &a, &b);
    for (int i =1; i <= n; i++){
        sumDig  =0;
        temp = i;
        while (temp != 0){
            digits = temp  % 10;
            sumDig += digits;
            temp /= 10;
            if (sumDig >= a && sumDig <= b){
                flag = 1;
            }else {
                flag = 0;
            }
        }
        if(flag == 1){
            temp = i;
            sumAll += temp ;    
        }
    }
    printf("%d\n", sumAll);


    return 0;
}