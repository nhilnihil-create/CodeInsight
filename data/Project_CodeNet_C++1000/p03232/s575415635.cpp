#include <bits/stdc++.h>
using namespace std;

int n;
long long a[100010];
long long mod = 1e9+7;
long long fact[100010];
long long s[100010];
long long ans;

long long inv(long long x){
	long long res = 1;
	for(int i=0; ((mod-2)>>i)>0; ++i){
		if((((mod-2)>>i) & 1) == 1){
			res *= x;
			res %= mod;
		}
		x *= x;
		x %= mod;
	}
	return res;
}

int main(){
//	cin.tie(0);
//	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n; ++i)
		cin >> a[i];
	fact[0] = 1;
	for(int i=1; i<=n; ++i)
		fact[i] = fact[i-1] * i % mod;
	for(int i=1; i<=n; ++i)
		s[i] = inv(i);
	for(int i=2; i<=n; ++i){
		s[i] += s[i-1];
		s[i] %= mod;
	}
	for(int i=1; i<=n; ++i){
		ans += a[i] * (s[i] + s[n-i+1] - 1) % mod;
		ans %= mod;
	}
	ans *= fact[n];
	ans %= mod;
	cout << ans << "\n";
}