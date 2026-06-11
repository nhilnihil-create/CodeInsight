#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
using P = pair<ll, ll>;
using V = vector<ll>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep1(i, n) for(ll i=1;i<=(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rep3(i, m, n) for(ll i=m;i<=(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define MOD 1000000007
#define INF 1000000000
#define LLINF 1000000000000000000

template<class T>bool chmax(T & a, const T & b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T & a, const T & b) { if (b < a) { a = b; return 1; } return 0; }

// 素数判定
bool is_prime(ll n) {
	if (n == 1) return false;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) return false;
	}
	return true;
}

void solve_abc_d() {
	ll n, m;
	ll l_ans = 0;

	cin >> n;

	V a(n);
	ll cnt = 0;
	rep(c, 5) {
		cnt = 0;
		for (ll p = c; p <= 55555; p += 5) {
			if (is_prime(p)) {
				a[cnt++] = p;
				if (cnt == n) {
					rep(i, n) {
						cout << a[i] << " ";
					}
					return;
				}
			}
		}
	}

	return;
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed;
	cout << setprecision(15);

	solve_abc_d();

	return 0;
}
