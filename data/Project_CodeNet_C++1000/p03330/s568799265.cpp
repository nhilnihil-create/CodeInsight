#include<bits/stdc++.h>
#define fi first
#define se second
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define rrep(i, n) for (int (i) = 1; (i) <= (n); (i++))
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define pb push_back
#define eb emplace_back
#define yn {puts("Yes");}else {puts("No");}
#define printd(x) printf("%.12f\n", ans);
template<class T> bool chmin(T& a, const T& b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> bool chmax(T& a, const T& b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void) {
	int n, C;
	cin >> n >> C;
	int d[C][C];
	rep (i, C) rep (j, C) cin >> d[i][j];
	int c[n][n];
	rep (i, n) rep (j, n) cin >> c[i][j];

	vector<int> per[3];
	rep (i, n) rep (j, n) {
		if ((i + j + 2) % 3 == 0) per[0].pb(c[i][j]);
		if ((i + j + 2) % 3 == 1) per[1].pb(c[i][j]);
		if ((i + j + 2) % 3 == 2) per[2].pb(c[i][j]);
	}

	int num[3][31] = {};
	rep (i, 3) {
		rep (j, per[i].size()) num[i][per[i][j]]++;
	}

	ll ans = 10000000000;
	rrep (col0, C) rrep (col1, C) rrep (col2, C) {
		if (col0 == col1 || col0 == col2 || col2 == col1) continue;

		int cols[] = {col0, col1, col2};

		ll sum = 0;
		rep (i, 3) rrep (col, C) {
			if (col != cols[i]) sum += d[col - 1][cols[i] - 1] * num[i][col];
		}
		chmin(ans, sum);
	}

	cout << ans << endl;
	return 0;
}