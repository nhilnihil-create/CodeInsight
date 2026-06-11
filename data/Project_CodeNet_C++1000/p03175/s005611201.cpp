#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n;
const ll nax = 1e5;
vector<ll> v[nax];
const ll mod = 1e9 + 7;


// (black, white)
pair<ll, ll> dfs(ll s, ll p){
	ll white = 1;
	ll black = 0;
	for(ll &c : v[s]){
		if(c == p) continue;
		pair<ll, ll> pf = dfs(c, s);
		black = ((1LL*(white+black)*pf.first)%mod + (1LL*black*pf.second)%mod)%mod;
		white = (white*pf.second)%mod;
	}
	return make_pair(white, (white + black)%mod);
}


int main(){
	ll n; cin >> n;
	for (ll i = 1; i < n; ++i)
	{
		ll a, b; cin >> a >> b;
		v[--a].push_back(--b);
		v[b].push_back(a);
	}
	auto p = dfs(0, -1);
	ll ans = (p.first+p.second)%mod;
	cout << ans;
}	