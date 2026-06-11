// IOI 2021
 
#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ends ' '
#define die(x) return cout << x << endl, 0
#define all(v) v.begin(), v.end()
#define sz(x) (int)(x.size())
#define debug(x) cerr << #x << ": " << x << endl
#define debugP(p) cerr << #p << ": {" << p.first << ", " << p.second << '}' << endl
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll INF = 1e9;
const int MOD = 998244353;//1e9 + 7;

////////////////////////////////////////////////////////////////////

const int N = 3e5 + 5;

int FAC[N], INV[N];

int Power(int a, int b) {
	int res = 1;
	for (; b; b >>= 1, a = 1LL * a * a % MOD) if (b & 1) res = 1LL * res * a % MOD;
	return res;
}
int C(int n, int k) { return k > n ? 0 : 1LL * INV[k] * INV[n - k] % MOD * FAC[n] % MOD; }

int main() {

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	FAC[0] = 1;
	for (int i = 1; i < N; i++) FAC[i] = 1LL * FAC[i - 1] * i % MOD;
	INV[N - 1] = Power(FAC[N - 1], MOD - 2);
	for (int i = N - 2; i >= 0; i--) INV[i] = 1LL * INV[i + 1] * (i + 1) % MOD;
	
	int n, a, b, ans = 0; cin >> n >> a >> b;
	ll k; cin >> k;
	for (int i = 0; i <= n && k >= 0; i++, k -= a) {
		if (k % b != 0 || k / b > n) continue;
		ans = (ans + 1LL * C(n, i) * C(n, k / b) % MOD) % MOD;
	}
	cout << ans << endl;

	return 0;
}
