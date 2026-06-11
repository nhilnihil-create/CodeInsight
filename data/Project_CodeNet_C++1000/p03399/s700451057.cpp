#include<stdio.h>
int main(void)
{
	int a,b,c,d,k,h;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	if(a<b){
		k=a;
	}
	else{
		k=b;
	}
	if(c<d){
		h=c;
	}
	else{
		h=d;
	}
	printf("%d\n",k+h);
	return 0;
}