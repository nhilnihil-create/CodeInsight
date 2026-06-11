#include <bits/stdc++.h>              
using namespace std;

#define INF 1.1e9
#define LINF 1.1e18
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) for (int i = (n) - 1; i >= 0; i--)
#define ALL(v) (v).begin(), (v).end()
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define BIT(x, n) bitset<n>(x)
#define PI 3.14159265358979323846

typedef long long ll;
typedef pair< int, int > P;
typedef pair< int, P > PP;

//-------------------------------------------------

int n;
ll a, ans, tmp = 1, ls[200001];
const int MOD = 1e9 + 7;

ll sqr(int x) {
	return (ll)x * x % MOD;
}

ll pow(int x, int y) {
	return y ? sqr(pow(x, y / 2)) * (y & 1 ? x : 1) % MOD : 1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

	cin >> n;
	FOR(i, 1, n + 1) ls[i] = (ls[i - 1] + pow(i, MOD - 2)) % MOD;
	FOR(i, 1, n + 1) {
		cin >> a;
		(ans += a * (ls[i] + ls[n - i + 1] - 1 + MOD) % MOD) %= MOD;
		(tmp *= i) %= MOD;
	}
	cout << ans % MOD * tmp % MOD << endl;

    return 0;
}                         


