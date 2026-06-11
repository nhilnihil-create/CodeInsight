#include <stdio.h>
main(){
    char a,b;scanf("%c %c",&a,&b);
    if(a>b) putchar('>');else if(a<b) putchar('<');else putchar('=');return putchar('\n'),0;
}