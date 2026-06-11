#include<stdio.h>
int main()
{
	int a,b,c,x;
	int i,j,k,n=0,m=0;
	scanf("%d %d %d %d",&a,&b,&c,&x);
	if(a*500+b*100+c*50<=0){
		printf("0\n");
	}
	for(i=0;i<=a;i++){
		for(j=0;j<=b;j++){
			for(k=0;k<=c;k++){
				n=i*500+j*100+k*50;
				if(n==x) m++;
			}
		}
	}
	printf("%d\n",m);
	return 0;
}