#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for(int i=0;i<(n);++i)
#define per(i, n) for(int i=(n)-1;i>=0;--i)
#define repa(i, n) for(int i=1;i<(n);++i)
#define foreach(i, n) for(auto &i:(n))
#define pii pair<int, int>
#define pll pair<long long, long long>
#define all(x) (x).begin(), (x).end()
#define bit(x) (1ll << (x))
const ll MOD = (ll)1e9+7;
const ll INF = (ll)1e9+7;
const ll INFLL = (ll)1e18;
using namespace std;
template<class t, class u> bool chmax(t &a, u b){if(a<b){a=b;return true;}return false;}
template<class t, class u> bool chmin(t &a, u b){if(a>b){a=b;return true;}return false;}

ll modpow(ll x, ll b){
	ll res = 1;
	while(b){
		if(b&1)res = res * x % MOD;
		x = x * x % MOD;
		b>>=1;
	}
	return res;
}

ll modinv(ll x){
	return modpow(x, MOD-2);
}

int main(){
	int n, k;
	cin >> n >> k;
	vector<ll> line(n);
	foreach(i, line)cin>>i;
	vector<ll> subs;
	rep(i, n){
		ll sum = 0;
		for(int j=i;j<n;++j){
			sum += line[j];
			subs.push_back(sum);
		}
	}

	auto func = [&](int hp){
		vector<ll> sub;
		foreach(i, subs)if(i&bit(hp))sub.push_back(i);
		if(sub.size()<k)return 0ll;
		ll res = bit(hp);
		per(i, hp){
			vector<ll> nsub;
			foreach(j, sub)if(j&bit(i))nsub.push_back(j);
			if(nsub.size()<k)continue;
			res |= bit(i);
			sub = nsub;
		}
		return res;
	};

	ll ans = 0;
	rep(i, 60)chmax(ans, func(i));
	cout << ans << endl;


	return 0;
}
