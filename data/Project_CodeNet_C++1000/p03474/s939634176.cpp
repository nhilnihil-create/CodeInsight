#include <stdio.h>

int main(){

    int a, b;
    int counter=0;
    char postal[100];
    scanf("%d %d", &a, &b);
    scanf("%s", postal);
  //  printf("%c", postal);

    for(int i=0;i<(a+b+1);i++){
        if(postal[a]!='-'){
            printf("No\n");
            break;
        }
        if(postal[i]>=48 && postal[i]<=57){
//            printf("masuk if ni");
            counter++;
        }
        else if(postal[i]=='-' && i!=a){
            printf("No\n");
            break;
        }

    }
if(counter==(a+b)){
    printf("Yes\n");
}
 
 
 
    return 0;
}