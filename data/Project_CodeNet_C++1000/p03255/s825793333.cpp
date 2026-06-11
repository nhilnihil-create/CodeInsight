#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef __int128 ll;

ll a[300000];
ll sum[300000];

int main(){
	long long N,X;cin>>N>>X;
	ll n=N,x=X;
	rep(i,n){
		long long A;scanf("%lld",&A);
		sum[i]=a[i]=A;
	}
	for(int i=1;i<n;i++)sum[i]+=sum[i-1];
	ll ans=LLONG_MAX;
	for(ll k=1;k<=n;k++){//何回往復するか?
		ll cnt=(n+k)*x;
		for(ll c=0;c<(n+k-1)/k;c++){
			ll l=max((ll)0,n-1-(c+1)*k+1),r=n-1-c*k;
			if(c==0)cnt+=(sum[r]-(l==0?0:sum[l-1]))*5;
			else cnt+=(2*c+3)*(sum[r]-(l==0?0:sum[l-1]));
		}
		ans=min(ans,cnt);
	}
	cout<<(long long)ans<<endl;
}