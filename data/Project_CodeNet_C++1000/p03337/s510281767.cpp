// if文による条件分岐　比較演算子
#include <stdio.h>
int main(void){
    int a,b;
    char buf[100];
    fgets(buf,sizeof(buf),stdin);
    sscanf(buf,"%d %d",&a,&b);
    int mx;
    mx=a+b;
    if (mx<=(a-b)) {
        mx=a-b;
    }
    if (mx<=(a*b)) {
        mx=a*b;
    }
    printf("%d",mx);
}
