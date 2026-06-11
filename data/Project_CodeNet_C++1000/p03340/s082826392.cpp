#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline int max(int x,int y) {return x>y?x:y;}
const int N=200009;
ll a[N],ps[N],px[N];
bool used[N];
int n;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		ps[i]=ps[i-1]+a[i];
		px[i]=px[i-1]^a[i];
	}
	ll ans=0;
	int maxl=-1;
	for(int i=1;i<=n;i++)
	{
		int l=i,r=n,pos;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			ll xor_sum=px[i-1]^px[mid],sum=ps[mid]-ps[i-1];
			if(xor_sum==sum) pos=mid,l=mid+1;
			else r=mid-1;
		}
		if(maxl>=pos) continue;
		ans+=(pos-i+2)*1ll*(pos-i+1)/2;
		if(maxl>=i) ans-=(maxl-i+2)*1ll*(maxl-i+1)/2;
		maxl=pos;
	}
	printf("%lld\n",ans);
	return 0;
}