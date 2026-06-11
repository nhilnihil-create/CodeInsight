#include <stdio.h>

int main () {
    int N,K ;
    char nama[55];
    scanf("%d%d %s",&N,&K,nama);
    nama[K-1]= nama[K-1]+32;
    printf("%s\n",nama);
    return 0;

}