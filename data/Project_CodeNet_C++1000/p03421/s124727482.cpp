#pragma comment(linker, "/STACK:640000000")
#include <bits/stdc++.h>

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define ll long long
#define bit __builtin_popcountll
#define sqr(x) (x) * (x)
#define forit(it,S) for(__typeof((S).begin()) it = (S).begin(); it != (S).end(); it++)

using namespace std;

typedef pair<int, int> pii;

const double eps = 1e-9;
const double pi = acos(-1.0);

int main() {
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif

	int n, a, b; cin >> n >> a >> b;

	if (a + b - 1 > n || a * 1LL * b < n) {
		cout << -1 << endl;
		return 0;
	}

	vector<int> v(n);

	for (int i = 0; i < n; i++) v[i] = n - i;

	for (int i = 0; i < a; i++) {
		cout << v[a - 1 - i] << " ";
	}

	int nxt = a;

	for (int i = 1; i < b; i++) {
		int cnt = min(a, n - nxt - (b - i - 1));

		for (int j = nxt + cnt - 1; j >= nxt; j--) {
			cout << v[j] << " ";
		}

		nxt += cnt;
	}

	return 0;
}