#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int, int> pii;
const ll INF = 1ll<<30;
const ll longINF = 1ll<<60;
const ll MOD = 1000000007;
const bool debug = 0;
//---------------------------------//

ll mod_pow(ll x, ll n, ll mod = MOD) {
	if (n == 0) return 1;
	ll res = mod_pow(x * x % mod, n / 2, mod);
	if (n & 1) res = res * x % mod;
	
	return res;
}

int N, A[112345];
ll sum[112345];

int main() {
	cin >> N;
	REP(i, N) scanf("%lld", A + i);
	
	FOR(i, 1, N + 1) sum[i] = (sum[i - 1] + mod_pow(i, MOD - 2, MOD)) % MOD;
	
	ll ans = 0;
	REP(i, N) {
		ll pat = 1;
		pat += sum[i + 1] - sum[1];
		pat += sum[N - i] - sum[1];
		pat %= MOD;
		
		(ans += pat * A[i] % MOD) %= MOD;
	}
	
	FOR(i, 1, N + 1) ans = ans * i % MOD;
	cout << ans << endl;
	
	return 0;
}
