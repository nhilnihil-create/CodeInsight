#include <bits/stdc++.h>
//#include "stdc++.h"
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = s; i < (int)(n); i++)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = max(a, b)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int		main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, x;
	cin >> n >> x;
	vector<int> v(n);
	rep(i, n) cin >> v[i];
	sort(all(v));
	rep(i, n) {
		if (x >= v[i] && i != n - 1) {
			x -= v[i];
			v[i] = 0;
		} else if (i == n - 1) {
			v[i] -= x;
			x = 0;
		}
	}

	cout << count(all(v), 0) << endl;
}
