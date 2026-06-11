#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

vector<ll> divisor(ll n){
	vector<ll> res;
	for(ll i = 1; i*i <= n; i++){
		if(n%i == 0){
			res.push_back(i);
			if(i != n/i) res.push_back(n/i);
		}
	}
	return res;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	ll ans = 0;
	for(auto p : divisor(n)){
		if(p == 1) continue;
		if(n/(p-1) == n%(p-1)) ans += p-1;
	}
	cout << ans << endl;
	return 0;
}