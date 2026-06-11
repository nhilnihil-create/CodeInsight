#include<stdio.h>
#include<string.h>

int main(){
    int A, B, count=0;
    scanf("%d%d", &A,&B);
    char add [A + B + 2];
    scanf("%s", add);
    
    for(int i = 0; i < A+B+1 ; i++){
        if(i != A){
            if( add[i] >= 48 && add[i] <= 57){
                count++;
            } 
        } else {if(add[i] == '-'){
                count++;
            }
        }
    }
    count == A+B+1 ? printf("Yes"):printf("No");
    return 0;
}