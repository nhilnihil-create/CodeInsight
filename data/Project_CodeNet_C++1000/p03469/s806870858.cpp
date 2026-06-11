#include<stdio.h>

int main(){
    
    char arr[105];
    scanf("%[^\n]", arr);
    
    arr[0] = '2';
    arr[1] = '0';
    arr[2] = '1';
    arr[3] = '8';
    
    printf("%s\n", arr);
    
    return 0;
}