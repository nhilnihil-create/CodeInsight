#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=2e5+7;
ll a[MAXN],b[MAXN],B[MAXN],A[MAXN];
int n;
inline ll find(ll k)
{
	int l=1,r=n+1;
	while(l<r){
		int mid=l+r>>1;
		if(B[mid]>=k) r=mid;
		else l=mid+1;
	}
	return l;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	ll ans=0;
	for(int k=1;k<=29;k++){
		ll base=(1<<k)-1;
		for(int i=1;i<=n;i++) B[i]=b[i]&base;
		for(int i=1;i<=n;i++) A[i]=a[i]&base;
		sort(B+1,B+n+1);
		ll cnt=0;
		for(int i=1;i<=n;i++)
			cnt+=n-find((1<<(k-1))-A[i])+1;
		for(int i=1;i<=n;i++)
			cnt-=find((1<<k)+(1<<(k-1))-A[i])-find((1<<k)-A[i]);
		if(cnt&1) ans+=(1<<(k-1));
	}
	cout<<ans;
}