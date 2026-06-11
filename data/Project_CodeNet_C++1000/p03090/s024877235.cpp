#include <bits/stdc++.h>
using namespace std;
#define repl(i, l, r) for (ll i = (l); i < (r); i++)
#define rep(i, n) repl(i, 0, n)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define CST(x) cout << fixed << setprecision(x)
using ll = long long;
const ll MOD = 1000000007;
const int inf = 1e9 + 10;
const ll INF = 4e18 + 10;
const int dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
const int dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	cout << n * (n - 1) / 2 - n / 2 << endl;
	if (n % 2) {
		repl(i, 1, n) {
			repl(j, i + 1, n + 1) {
				if (i + j == n)
					continue;
				else
					cout << i << " " << j << endl;
			}
		}
	} else {
		repl(i, 1, n) {
			repl(j, i + 1, n + 1) {
				if (i + j == 1 + n)
					continue;
				else
					cout << i << " " << j << endl;
			}
		}
	}

	return 0;
}