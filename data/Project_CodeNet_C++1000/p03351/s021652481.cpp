// if文による条件分岐　比較演算子
#include <stdio.h>
#include <stdlib.h>
int main(void){
    char buf[100];
    int a,b,c,d;
    fgets(buf,sizeof(buf),stdin);
    sscanf(buf, "%d %d %d %d",&a, &b, &c, &d);
    int l1,l2,l3;
    l1=abs(b-a);
    l2=abs(c-b);
    l3=abs(c-a);
    if (l3<=d || (l1<=d && l2<=d)) {
        printf("Yes");
    } else {
        printf("No");
    }
}