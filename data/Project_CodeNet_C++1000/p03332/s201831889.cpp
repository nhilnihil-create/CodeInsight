#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define int long long
#define INF 1000000000
#define MOD 998244353
int n, fact[364364], ans;
int k;
int modpow(int a, int b) {
	if (b == 0)return 1;
	if (b % 2)return modpow(a, b - 1)*a%MOD;
	return modpow(a, b / 2)*modpow(a, b / 2) % MOD;
}
int comb(int x) {
	return fact[n] * modpow(fact[x], MOD - 2) % MOD*modpow(fact[n - x], MOD - 2) % MOD;
}
signed main() {
    int a,b;
	cin >> n >> a >> b >> k;
	fact[0] = 1;
	for (int i = 1; i <= n; i++)fact[i] = fact[i - 1] * i%MOD;
	rep(i, n + 1) {
		if ((k - a * i) % b!=0)continue;
		if ((k - a * i) / b > n||(k-a*i)/b<0)continue;
		int x = i, y = (k - a * i) / b;
		ans += comb(x) * comb(y)%MOD;
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}
