#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()
#define dump(x) cout << #x << " = " << (x) << endl
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

template<class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	os<<"{";
	rep(i, v.size()) {
		if (i) os<<",";
		os<<v[i];
	}
	os<<"}";
	return os;
}

inline void chmin(ll &x, ll y) { if (x >= y) x = y; }

ll dp[5010][5010];
const ll INF = TEN(18);

int main() {
	int N; ll A, B;
	cin >> N >> A >> B;
	vi p(N);

	rep(i, N) {
		cin >> p[i];
	}

	rep(i, 5010) {
		rep(j, 5010) {
			dp[i][j] = INF;
		}
	}

	dp[0][p[0]] = 0;
	dp[0][0] = A;

	for (int i = 1; i < N; ++i) {
		dp[i][p[i]] = A * i;
		rep(j, 5010) if (dp[i-1][j] != INF) { //skip
			chmin(dp[i][j], dp[i-1][j] + (p[i] < j ? B : A));
		}
		//fix
		rep(j, p[i]) {
			chmin(dp[i][p[i]], dp[i-1][j]);
		}
	}

	ll mini = INF;
	rep(j, 5010) chmin(mini, dp[N-1][j]);
	cout << mini << endl;
	return 0;
}