

#include<stdio.h>


int main(){
     
    int N;
    int K;
    char Str[100];
    scanf("%d %d", &N, &K);
    scanf("%s", &Str);
    Str[K-1]= Str[K-1]+32;
    printf("%s", Str);
    
		
    
    
    
     
     
     
     
    
    return 0;
}