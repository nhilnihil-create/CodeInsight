#include <stdio.h>
int main(void){
    // Here your code !
    char buf[100];
    int a;
    int b;
    fgets(buf,sizeof(buf),stdin);
    sscanf(buf, "%d %d",&a,&b);
    if ((a<=8) && (b<=8)) {
        printf("Yay!");
    } else  {
        printf(":(");
    }
    //printf("%d\n",a);
    //printf("%d\n",b);

}