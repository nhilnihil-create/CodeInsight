#include <bits/stdc++.h>
using namespace std;
long long n,m,i,j,a[200005],sum[200005],ans=0x7fffffffffffffffll,ss,t;
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	for (i=1;i<=n;i++) cin>>a[i];
	for (i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for (i=1;i<=n;i++)
	{
		j=n;ss=0;t=3;
		while (j>0)
		{
			ss+=max(t,5ll)*(sum[j]-sum[max(j-i,0ll)]);
			if (ss>ans) break;
			j=max(0ll,j-i);
			t+=2;
		}
		ans=min(ans,ss+i*m);
	}
	cout<<n*m+ans;
	return 0;
}