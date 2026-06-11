#include <stdio.h>

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    char str[a+b+2];
    scanf("%s", str);
    
    int flag = 1;
    
    if(str[a] != '-'){
        flag = 0;
    }
    
    else{
        for(int i = 0; str[i] != '\0'; i++){
            if(i != a && str[i] >= 48 && str[i] <= 57){
                
            }
            else if(i != a && (str[i] <48 || str[i] >57)){
                flag = 0;
            }
        }
    }
    
    flag ? printf("Yes\n") : printf("No\n");
    
    return 0;
}
