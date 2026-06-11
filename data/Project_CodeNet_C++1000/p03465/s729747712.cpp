#include <bits/stdc++.h>
using namespace std;
const int M=4000005;
const int N=2005;

int sum=0,n,a[N];
bitset<M> bit;

int main() 
{
	scanf("%d",&n);
	bit[0]=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		bit|=(bit<<a[i]);
		sum+=a[i];
	}
	for(int i=(sum+1)/2;i<=sum;i++) if(bit[i])
	{
		printf("%d\n",i);
		return 0;
	}
	return 0;
}
