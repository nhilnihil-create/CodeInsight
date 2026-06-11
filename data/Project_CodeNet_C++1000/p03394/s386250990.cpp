#include<cstdio>
using namespace std;
int n,i,sum=0;
int main()
{
	scanf("%d",&n);
	if(n==3)
	{
		printf("2 5 63\n");
		return 0;
	}
	printf("2 ");
	sum=2;
	n--;
	for(i=4;n>5000||n%2||sum%3!=0;i+=2)
	{
		printf("%d ",i);
		sum+=i;
		n--;
	}
	for(i=3;n;i+=3)
	{
		if(i%2==0)continue;
		printf("%d ",i);
		n--;
	}
	return 0;
}