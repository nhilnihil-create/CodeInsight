#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

#define fr first
#define sc second

const ll INF=1000000000000000000;

int main(){
	static ll n;
	static ll a[200010];
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	
	static ll sum[200010];
	sum[0]=0;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	
	ll ret=INF;
	int l=0,r=2;
	for(int i=2;i<=n-2;i++){
		while(min(sum[i]-sum[l],sum[l])<=min(sum[i]-sum[l+1],sum[l+1]))l++;
		while(min(sum[n]-sum[r],sum[r]-sum[i])<=min(sum[n]-sum[r+1],sum[r+1]-sum[i]))r++;
		ll MAX=max(max(sum[n]-sum[r],sum[r]-sum[i]),max(sum[i]-sum[l],sum[l]));
		ll MIN=min(min(sum[n]-sum[r],sum[r]-sum[i]),min(sum[i]-sum[l],sum[l]));
		ret=min(ret,MAX-MIN);
	}
	cout<<ret<<endl;
}

