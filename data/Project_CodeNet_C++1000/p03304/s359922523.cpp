#include<stdio.h>
int main(){float n,m,d;scanf("%f%f%f",&n,&m,&d);printf("%lf",(d?2:1)*(n-d)*(m-1)/n/n);}