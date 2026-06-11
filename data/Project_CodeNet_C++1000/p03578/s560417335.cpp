#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){

    ll n; cin >> n;
	map<ll, ll> mp;
	for(ll i = 0; i < n; ++i){
		ll tmp; cin >> tmp;
		mp[tmp]++;
	}
	ll m; cin >> m;
	for(ll i = 0; i < m; ++i){
		ll tmp; cin >> tmp;
		if(mp[tmp] > 0){
			mp[tmp]--;
		}
		else{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
    return 0;
}
