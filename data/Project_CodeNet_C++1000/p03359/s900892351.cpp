// if文による条件分岐　比較演算子
#include <stdio.h>
#include <stdlib.h>
int main(void){
    char buf[100];
    int a,b;
    fgets(buf,sizeof(buf),stdin);
    sscanf(buf,"%d %d",&a,&b);
    int ans;
    if (b>=a) {
        ans=a;
    } else {
        ans=a-1;
    }
    printf("%d",ans);
}
