#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define REP(i, n) for (ll (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n) for (ll (i) = m ; (i) < (ll)(n) ; ++(i))
#define REP_REV(i, n) for (ll (i) = (ll)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (ll (i) = (ll)(n) - 1 ; (i) >= m ; --(i))
#define ALL(x) x.begin(), x.end()

//#define INF (1e10)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
template<class T> void print(const T& x) { cout << x << endl; }
template<class T, class... A> void print(const T& first, const A& ... rest) { cout << first << " "; prll(rest...); }
struct PreMain { PreMain() { cin.tie(0); ios::sync_with_stdio(false); } } premain;

int main() {
	int N, Z, W;
	cin >> N >> Z >> W;

	vector<ll> A(N);

	REP(i, N) {
		cin >> A[i];
	}

	ll ans = 0;
	if (1 == N) {
		ans = (abs(A[0] - W));
	}
	else {
		ans = max(abs(A[N - 1] - W), abs(A[N - 2] - A[N - 1]));
	}
	print(ans);

	return 0;
}
