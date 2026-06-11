#include<bits/stdc++.h>
using namespace std;
bitset<4000010>f;
int n,a,sum;
int main()
{
	f[0]=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		f|=f<<a;
		sum+=a;
	}
	for(int i=(sum+1)>>1;i<=sum;i++)
		if(f[i])
		{
			printf("%d\n",i);
			return 0;
		}
}