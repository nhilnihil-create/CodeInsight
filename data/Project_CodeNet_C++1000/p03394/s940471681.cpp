#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    
    if(n == 3){
        printf("2 5 63");
        return 0;
    }
    if(n < 30){
        printf("3 9 ");
        if((n-2) % 3 == 0 || (n-2) % 3 == 2){
            for(int i = 1; i <= n-2; i++){
                printf("%d ", 2 * i);
            } 
        } else {
            for(int i = 1; i <= n-2; i++){
                printf("%d ", 2 * i + 4);
            }
        }
        return 0;
    }
    
    
    int nNumTwo, nNumThree, nNumFive;  //それぞれ和が30の倍数となるように作る
    nNumFive = min(2000 , (n / 6) * 2);   //5の倍数\2または3の倍数の個数
    nNumThree = min(5000 , (n / 30) * 10);  //3の倍数\2の倍数の個数
    nNumTwo = n - nNumFive - nNumThree;  //2の倍数の個数
    
    int nSum = 0;
    for(int i = 1; i < nNumTwo; i++){
       printf("%d ", 2 * i);
       nSum += 2 * i;
    }
    int nTwoLast = (2 * nNumTwo + 60) / 30;
    nTwoLast *= 30;
    nTwoLast -= (nSum % 30);
    printf("%d ", nTwoLast);
    
    for(int i = 0; i < nNumThree; i++){
        printf("%d ", 6 * i + 3);
    }
    
    for(int i = 0; i < nNumFive; i++){
        if(i % 2 == 0){
            printf("%d ", 15 * i + 5);
        }
        else {
            printf("%d ", 15 * i + 10);
        }
    }
  
    return 0;
}
