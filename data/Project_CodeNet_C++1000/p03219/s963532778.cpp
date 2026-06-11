#include<stdio.h>

int main ()
{
    int x,y,z,ttl;
    scanf("%d%d",&x,&y);
    if(y%2==0){
    z=y/2;
    ttl=x+z;
    printf("%d\n",ttl);}
    else 
    printf("%d\n",y);
  
    return 0;
}