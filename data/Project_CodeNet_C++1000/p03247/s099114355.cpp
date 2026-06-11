#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

const int MAXN = 2000;
int n;
ll x[MAXN];
ll y[MAXN];
ll dx[] = {0, 0, 1, -1};
ll dy[] = {1, -1, 0, 0};
char ch[] = {'U', 'D', 'R', 'L'};
const ll INF = 1e18;


int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> x[i] >> y[i];
	int fl = 0;
	if ((x[0] + y[0]) % 2 == 0) {
		fl = 1;
		for (int i = 0; i < n; ++i)
			--x[i];
	}
	for (int i = 0; i < n; ++i) {
		if ((x[i] + y[i]) % 2 == 0) {
			cout << -1 << "\n";
			return 0;
		}
	}
	vector<ll> vv;
	for (int i = 0; i <= 31; ++i)
		vv.push_back(1ll << i);
	if (fl)
		vv.push_back(1);
	reverse(vv.begin(), vv.end());
	cout << vv.size() << "\n";
	for (ll x: vv)
		cout << x << " ";
	cout << "\n";
	for (int i = 0; i < n; ++i) {
		string s;
		if (fl)
			s += "R";
		for (int j = 31; j >= 0; --j) {
			int bst = -1;
			ll now = INF;
			for (int k = 0; k < 4; ++k) {
				ll cur = abs(x[i] - dx[k] * (1ll << j)) + abs(y[i] - dy[k] * (1ll << j));
				if (cur < now)
					now = cur, bst = k;
			}
			x[i] -= dx[bst] * (1ll << j);
			y[i] -= dy[bst] * (1ll << j);
			s += ch[bst];
		}
		cout << s << "\n";
	}
	return 0;
}
