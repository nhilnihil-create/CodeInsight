#include<bits/stdc++.h>
using namespace std;
int n,k;
double ans,tx;
int main()
{
	int x;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		x=i;tx=1;
		for(int j=1;x<k;j++)x*=2,tx*=0.5;
		ans+=1.0/n*tx;
	}
	printf("%.9lf",ans);
	return 0;
}