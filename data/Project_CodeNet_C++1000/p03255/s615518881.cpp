#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
int n,x,a[maxn],e[maxn];
long long sum[maxn],ans,s;
int main()
{
	cin>>n>>x;
	for(int i=1;i<=n;i++) cin>>a[i];
	reverse(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	e[1]=e[2]=5;
	for(int i=3;i<=n;i++) e[i]=e[i-1]+2;
	ans=1e18;
	for(int k=1;k<=n;k++) 
	{
		s=(long long)(n+k)*x;
		for (int i=1,cnt=1;i<=n;i+=k,cnt++)
		{
		    s+=(long long)(sum[min(i+k-1,n)]-sum[i-1])*e[cnt];
			if(s>ans) break;
		}
		ans=min(ans,s);
	}
	cout<<ans<<endl;
	return 0;
}
