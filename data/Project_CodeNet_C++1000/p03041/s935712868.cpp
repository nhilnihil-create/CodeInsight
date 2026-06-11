#include<stdio.h>
int main (){

    char strS[52];
    int N;
    int K;

    1<=N<=50;

    1<=K<=N;

    scanf("%d %d", &N, &K);

    scanf("%s", &strS);

    strS[K-1] += 32;

    printf("%s", strS);


    return 0;
}