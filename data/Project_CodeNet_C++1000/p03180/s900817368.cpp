#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll INF = 1e18;

vector<ll> dp, pre;

void go(ll i, const vector<ll> &v, ll mask, ll group, ll x){
	if(i == (ll)v.size()){
		dp[mask] = max(dp[mask], pre[group] + x);
		return;
	}
	go(i+1, v, mask, group, x);
	go(i+1, v, mask^(1<<v[i]), group^(1<<v[i]), x);
}


int main(){
	ll n; cin >> n;
	ll a[n][n];
	for(ll i = 0; i < n; ++i){
		for(ll j = 0; j < n; ++j){
			cin >> a[i][j];
		}
	}
	pre.resize(1<<n);
	for(ll mask = 0; mask < (1<<n); ++mask){
		ll t = mask, b = 0, t1 = 0;
		vector<ll> v;
		while(t){
			if(t&1){
				for(const ll &j : v){
					t1 += a[b][j];
				}
				v.push_back(b);
			}
			t >>= 1; ++b;
		}
		pre[mask] = t1;
	}
	dp.resize(1<<n, -INF);
	dp[0] = 0;
	for(ll mask = 0; mask < (1<<n); ++mask){
		vector<ll> v;
		for(ll i = 0; i < n; ++i){
			if(!(mask&(1<<i))) v.push_back(i);
		}
		go(0, v, mask, 0, dp[mask]);
	}
	cout << (ll)dp[(1<<n) - 1];
}