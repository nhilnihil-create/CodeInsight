#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
	int n, m;
	cin >> n >> m;
	if (m <= n) { cout << 0 << endl; return 0; }
	vector<int>x(m),xs(m-1);
	rep(i, m)cin >> x[i];
	sort(all(x));
	rep(i, m-1) {
		xs[i] = x[i + 1] - x[i];
	}
	sort(rall(xs));
	cout << accumulate(xs.begin() + n-1, xs.end(), 0) << endl;;
	return 0;
}

