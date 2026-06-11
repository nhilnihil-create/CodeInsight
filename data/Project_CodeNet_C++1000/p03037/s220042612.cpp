#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)n; ++i)
#define FOR(i, a, b) for(int i = a; i < (int)b; ++i)

using ll = long long;

const int Inf = 100100100;
const double EPS = 1e-9;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<int> sum(n + 1);
	rep (i, m) {
	  int l, r;
	  cin >> l >> r;
	  sum[l - 1]++, sum[r]--;
	}
	rep (i, n) sum[i + 1] += sum[i];
	int res = 0;
	rep (i, n) if (sum[i] == m) res++;
	cout << res << endl;
	
    return 0;
}
