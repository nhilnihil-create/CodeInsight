#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define db double
#define pb push_back
#define ppb pop_back
#define F first
#define S second
#define mp make_pair
#define all(x) (x).begin(), (x).end()

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 103;
int n, g[N][N];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			g[i][j] = 1;
		}
	}
	int k = n;
	if (n & 1) {
		k--;
	}
	for (int i = 1; i <= n / 2; i++) {
		g[i][k - i + 1] = 0;
	}
	vector <pii> vec;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (g[i][j]) {
				vec.pb({i, j});
			}
		}
	}
	cout << vec.size() << '\n';
	for (auto i : vec) {
		cout << i.F << ' ' << i.S << '\n';
	}
}
