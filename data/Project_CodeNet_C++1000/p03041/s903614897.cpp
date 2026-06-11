#include <stdio.h>

int main(){

    char S[50];
    int N,K;

    scanf("%d %d",&N,&K);
    getchar();
    scanf("%s",&S);

    S[K-1]=S[K-1]+32;

    printf("%s",&S);

    return 0;
}