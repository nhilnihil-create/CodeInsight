#include<bits/stdc++.h>
using namespace std;

using ll = long long;
double f(ll a){
	ll s = 0;
	for(ll t = a; t; t /= 10) s += t % 10;
	return a * 1.0 / s;
}

int main(){
	int k; cin >> k;
	ll LIM = 3e16;
	vector<ll> v, ans;
	for(int i = 1; i <= 9999; i++) for(ll j = i; j < LIM; j = j * 10 + 9) v.push_back(j);
	sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());
	double mn = 1e18;
	for(int i = v.size() - 1; i >= 0; i--){
		double s = f(v[i]);
		if(mn + 1e-9 > s){
			mn = s;
			ans.push_back(v[i]);
		}
	}
	reverse(ans.begin(), ans.end());
	for(int i = 0; i < k; i++) cout << ans[i] << endl;
	return 0;
}