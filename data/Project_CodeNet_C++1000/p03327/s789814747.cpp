// if文による条件分岐　比較演算子
#include <stdio.h>
int main(void){
    char buf[100];
    int a;
    fgets(buf,sizeof(buf),stdin);
    sscanf(buf,"%d",&a);
    if (a<=999) {
        printf("ABC");
    } else {
        printf("ABD");
    }
}