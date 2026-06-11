#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll a[1010],sum[1010];
int main(){
	ll n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	vector<ll>v;
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)v.push_back(sum[j]-sum[i-1]);
	ll ans=0;
	for(int i=40;i>=0;i--){
		ll cnt=0,t=(1ll<<i);
		for(ll x:v){
			if((x&(ans+t))==ans+t)cnt++;
		}
		if(cnt>=k)ans+=t;
	}
	cout<<ans;
	return 0;
}