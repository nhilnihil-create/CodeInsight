#include <stdio.h>

int main(){
int tinggi, alas;
int diagonal, luas;

scanf("\n%d %d %d",&tinggi,&alas,&diagonal);
luas = (tinggi * alas)/2;

printf("\n%d",luas);

return 0;
}