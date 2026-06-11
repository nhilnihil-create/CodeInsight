#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> p2;
const ll hell=4000005;
ll cnt[2005];
void solve(){
	ll n,sum=0;
	cin>>n;
	for(ll i=0;i<n;i++){
		ll x;
		cin>>x;
		sum+=x;
		cnt[x]++;
	}
	sum=(sum+1)/2;
	vector<ll> v;
	for(ll i=1;i<=2000;i++)
	if(cnt[i]){
		for(ll j=0;(1<<j)<=cnt[i];j++){
			v.push_back((1<<j)*i);
			cnt[i]-=(1<<j);
		}
		if(cnt[i])
		v.push_back(cnt[i]*i);
	}
	bitset<hell> dp;
	dp.set(0);
	for(ll i=0;i<ll(v.size());i++)
	dp|=(dp<<v[i]);
	while(sum<4000005){
		if(dp.test(sum)){
			cout<<sum;
			exit(0);
		}
		sum++;
	}
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll qc=1;
    for(ll i=1;i<=qc;i++)
    solve();
}
