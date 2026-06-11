#include<bits/stdc++.h>
using namespace std;
long long n,a[222222],sum,pos,cur,A,b,c,d,mn,mx,ans;
pair<long long,long long> pre[222222],suf[222222];
long long calc(long long a,long long b)
{
	return abs(a-2*b);
}
int main()
{
	scanf("%lld",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sum=0;pos=1;
	for (int i=1;i<=n;i++)
	{
		sum+=a[i];
		while(pos<=i && calc(sum,cur)>calc(sum,cur+a[pos])) 
		{
			cur+=a[pos];pos++;
		}
		pre[i]=make_pair(cur,sum-cur);
	}
	sum=cur=0;pos=n;
	for (int i=n;i>=1;i--)
	{
		sum+=a[i];
		while(pos>=i && calc(sum,cur)>calc(sum,cur+a[pos]))
		{
			cur+=a[pos];pos--;
		}
		suf[i]=make_pair(cur,sum-cur);
	}
	ans=1e18;
	for (int i=2;i<n;i++)
	{
		A=pre[i].first;b=pre[i].second;c=suf[i+1].first;d=suf[i+1].second;
		mn=min(min(A,b),min(c,d));mx=max(max(A,b),max(c,d));
		if (mn==0) continue;
		ans=min(ans,mx-mn);
	}
	printf("%lld\n",ans);
	return 0;
}