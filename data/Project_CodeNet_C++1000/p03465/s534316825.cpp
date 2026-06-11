#include<bits/stdc++.h>
using namespace std;
int n,x,sum;
bitset<2000007>f;
signed main()
{
	scanf("%d",&n);
	f[0]=1;
	for(register int i=1;i<=n;++i)
	scanf("%d",&x),f|=f<<x,sum+=x;
	for(register int i=(sum+1)>>1;i<=sum;++i)
	if(f[i]) 
	if(printf("%d",i))
	break;
	return 0;
}