#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<ll,ll> ii;
const int N = 2e5+1;
ll a[N];
ll pre[N];
ll ans = 1e18;
ll sum(int l,int r)		{	return pre[r] - pre[l-1];	}
int main()
{
	pre[0]=0ll;
	int n,i,j,k,l,r,pos;
	scanf("%d",&n);
	for(i=1;i<=n;++i)	scanf("%lld",&a[i]);
	for(i=1;i<=n;++i)	pre[i] = pre[i-1] + a[i];
	for(i=2;i<=n;++i)
	{
		l=1;r=i-1;pos=l;
		while(l<=r) 
		{
			int mid=(l+r)/2;
			if(2*pre[mid]>pre[i]) 	r=mid-1;
			else 					
			{
				pos=mid;
				l=mid+1;
			}
		}
		int lower_bound=pos;
		l=i+1;r=n-1;pos=l;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(2*sum(i+1,mid)>sum(i+1,n)) r=mid-1;
			else 							
			{
				pos=mid;
				l=mid+1;
			}
		}
		int upper_bound=pos;
		for(j=lower_bound-5;j<=lower_bound+5;j++)
		{
			for(k=upper_bound-5;k<=upper_bound+5;k++)
			{
				if(j>0&&j<i&&k>i&&k<n)
				{
					ll a = pre[j];
					ll b = sum(j+1,i);
					ll c = sum(i+1,k);
					ll d = sum(k+1,n);
					ll mn = min(min(a,b),min(c,d));
					ll mx = max(max(a,b),max(c,d));
					ans=min(ans,mx-mn);
				}
			}
		}
	}	
	printf("%lld",ans);
}
