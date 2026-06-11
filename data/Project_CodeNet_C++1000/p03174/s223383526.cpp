#include "bits/stdc++.h"
using namespace std;
 
using ll = long long;
 
const ll inf = 1e18;
const ll mod = 1e9 + 7;
const int N = 1 << 21;

ll n;
ll res;
ll a[N];
std::vector<ll> v[22];
ll dp[22][N];
ll go(ll idx, ll mask){
	if(idx == n){
		if(mask == (1LL << n) - 1) return 1;
		return 0;
	}
	if(dp[idx][mask] + 1) return dp[idx][mask];
	ll xx = 0;
	for (int i = 0; i < v[idx].size(); ++i){
		if(v[idx][i] && !(mask & (1LL << i))){
			xx += go(idx + 1, mask | (1LL << i));
			xx %= mod;
		}
	}
	return dp[idx][mask] = xx;
}

void solve(){
	cin >> n;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			cin >> res;
			v[i].push_back(res);
		}
	}
	memset(dp, -1, sizeof dp);
	cout << go(0, 0);
}
 
int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    ll t = 1;
    //cin >> t;
    while(t--){
    	solve();
    }
}
// smf