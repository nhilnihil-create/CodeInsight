#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using G = vector<vector<int>>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const ll MOD = 1000000007;

ll GCD(ll x, ll y){
	return y ? GCD(y, x%y) : x;	
}

int main() {
	ll n, m; cin >> n >> m;
	vector<ll> v;
	for(ll i=1;i*i<=m;i++){
		if(m%i==0){
			v.push_back(i);
			v.push_back(m/i);
		}
	}
	sort(v.rbegin(), v.rend());
	for(auto c: v){
		if(c<=m/n){
			cout << c << endl;
			return 0;
		}
	}
	return 0;
}