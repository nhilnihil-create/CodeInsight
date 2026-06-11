#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ll mod = 1000000007;

inline ll modPow(ll a, ll b){
	ll ret = 1;
	while(b){
		if(b&1)(ret *= a) %= mod;
		(a *= a) %= mod;
		b >>= 1;
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	string s;
	cin>>s;
	int n = s.size();
	vector<int> a(n), c(n), qf(n), qb(n);
	for(int i = 0; i < n; i++){
		if(s[i] == 'A')a[i] = 1;
		if(s[i] == '?')qf[i] = 1;
		if(i){
			a[i] += a[i - 1];
			qf[i] += qf[i - 1];
		}
	}
	for(int i = n - 1; i >= 0; i--){
		if(s[i] == 'C')c[i] = 1;
		if(s[i] == '?')qb[i] = 1;
		if(i + 1 < n){
			c[i] += c[i + 1];
			qb[i] += qb[i + 1];
		}
	}
	ll ans = 0;
	for(int i = 1; i + 1 < n; i++){
		if(s[i] == 'B' || s[i] == '?'){
			ll tmp1 = a[i - 1];
			if(qf[i - 1]){
				tmp1 = (qf[i - 1] + 3*a[i - 1])*modPow(3, qf[i - 1] - 1)%mod;
			}
			ll tmp2 = c[i + 1];
			if(qb[i + 1]){
				tmp2 = (qb[i + 1] + 3*c[i + 1])*modPow(3, qb[i + 1] - 1)%mod;
			}
			ans += tmp1*tmp2%mod;
			if(ans >= mod)ans -= mod;
		}
	}
	cout<<ans<<'\n';

	return 0;
}