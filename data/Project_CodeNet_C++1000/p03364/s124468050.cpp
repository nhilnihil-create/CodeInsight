#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = 1'000'000'007;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N; cin >> N;
	vector<vector<char>> v(N, vector<char>(N));
	rep(i, 0, N) rep(j, 0, N) { cin >> v[i][j]; }

	int ans = 0;
	rep(a, 0, N) {
		bool ok = true;
		rep(i, 0, N) {
			rep(j, 0, N) {
				if (v[(i + a) % N][j] != v[(j + a) % N][i])
					ok = false;
			}
		}
		if (ok)ans += N;
		dump(a, ok);
	}
	cout << ans << endl;

	return 0;
}