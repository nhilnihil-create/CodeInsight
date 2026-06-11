#include<cstdio>
int main()
{
	int a,b,n;
	n=0;
	scanf("%d %d",&a,&b);
	if(a>=b){
		n+=a;
		a-=1;
	}
	else{
		n+=b;
		b-=1;
	}
	if(a>=b) n+=a;
	else n+=b;
	printf("%d\n",n);
	return 0;
}
