#include<bits/stdc++.h>
using namespace std;

bitset<4000020> b;

int n,a,c=0,cc;

int main()
{
	scanf("%d",&n);
	b[0]=1;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a);
		b|=b<<a,c+=a;
	}
	cc=c;
	c=(c+1)>>1;
	for(int i=c;i<=cc;++i)
	{
		if(b[i])
		{
			printf("%d\n",i);
			return 0;
		}
	}
	
	return 0;
}