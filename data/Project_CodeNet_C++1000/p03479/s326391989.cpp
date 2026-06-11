#include<stdio.h>
using namespace std;int main(){long int x,y,c=0;scanf("%ld %ld", &x, &y);while(x <= y){x *= 2;++c;}printf("%d\n", c);}