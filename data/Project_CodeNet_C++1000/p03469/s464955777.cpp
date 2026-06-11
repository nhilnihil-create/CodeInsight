#include <stdio.h>

int main(){
    char arr[10];
    scanf("%s",arr);
    arr[0] = '2';
    arr[1] = '0';
    arr[2] = '1';
    arr[3] = '8';
    for(int i=0; i<10;i++){    
    printf("%c",arr[i]);
    }
    return 0;
}