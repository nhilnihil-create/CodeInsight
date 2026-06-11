#include<bits/stdc++.h>
using namespace std;
bitset<2000005>bs;
int n,sum;
int main()
{
	cin>>n;
	bs[0]=1;
	for(int i=1,x;i<=n;i++)
	{
		scanf("%d",&x);
		bs|=bs<<x;
		sum+=x;
	}
	for(int i=(sum+1)>>1;i<=sum;i++)
		if(bs[i])
			return printf("%d\n",i),0;
	puts("徐熙来AKKING");
	return 0;
}