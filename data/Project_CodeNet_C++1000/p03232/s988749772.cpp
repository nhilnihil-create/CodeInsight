#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using ii = pair<int, int>;
constexpr ll MOD = 1e9+7;

ll pw(ll base, ll exp) {
	ll res = 1;
	while (exp) {
		if (exp & 1) (res *= base) %= MOD;
		exp >>= 1, (base *= base) %= MOD;
	}
	return res;
}

ll inv(ll x) { return pw(x, MOD - 2); }

ll A[100001], P[100001];

int main() {
    if (fopen("in", "r")) freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0);

    int N; cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];

    for (int i = 0; i < N; ++i) (P[i+1] = inv(i+1)+P[i]) %= MOD;

    ll ans = 0;
    for (int i = 0; i < N; ++i) (ans += A[i]*(P[i+1]+P[N-i] - 1) % MOD) %= MOD;
    for (int i = 0; i < N; ++i) (ans *= (i+1)) %= MOD;
    cout << ans;
}