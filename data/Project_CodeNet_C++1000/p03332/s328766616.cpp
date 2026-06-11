#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353, maxn = 303030;
int mul(long long a, long long b){
	return a * b % mod;
}
int xp(int a, int b){
	int r = 1;
	for(; b; b >>= 1, a = mul(a, a)) if(b&1) r = mul(r, a);
	return r;
}
int fat[maxn], ifat[maxn];
void init(){
	fat[0] = 1;
	for(int i = 1; i < maxn; i++) fat[i] = mul(i, fat[i - 1]);
	ifat[maxn - 1] = xp(fat[maxn - 1], mod - 2);
	for(int i = maxn - 2; i >= 0; i--) ifat[i] = mul(i + 1, ifat[i + 1]);
}
int ncr(int n, int r){
	if(n < r) return 0;
	return mul(fat[n], mul(ifat[r], ifat[n - r]));
}
int main(){
	init();
	int n, a, b; long long k; cin >> n >> a >> b >> k;
	int ans = 0;
	for(int i = 0; i <= n; i++){
		long long nk = k - 1ll * a * i;
		if(nk >= 0 && (nk%b) == 0 && nk/b <= n){
			ans += mul(ncr(n, i), ncr(n, nk/b));
			if(ans >= mod) ans -= mod;
		}
	}
	cout << ans << endl;
	return 0;
}

