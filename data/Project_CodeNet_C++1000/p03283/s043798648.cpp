#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	int n, m, Q;
	cin >> n >> m >> Q;
	vector<int> l(m), r(m), p(Q), q(Q);
	rep(i, m) {
		cin >> l[i] >> r[i];
		l[i]--; r[i]--;
	}
	rep(i, Q){
		cin >> p[i] >> q[i];
		p[i]--; q[i]--;
	}
	vector<vector<int>> v(n, vector<int>(n));
	rep(i, m) {
		v[l[i]][r[i]]++;
	}
	rep(i, n) {
		rep(j, n-1) {
			v[i][j+1] += v[i][j];
		}
	}
	rep(j, n) {
		for(int i = n-1; i > 0; i--) {
			v[i-1][j] += v[i][j];
		}
	}
	rep(i, Q) {
		printf("%d\n", v[p[i]][q[i]]);
	}
	return 0;
}