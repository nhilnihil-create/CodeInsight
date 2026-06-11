#include <cstdio>
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    int avg=(a+b)/2;
    if((a+b)%2==1){
        printf("%d",avg+1);
    }
    else{
        printf("%d",avg);
    }
}
