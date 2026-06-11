#include <bits/stdc++.h>
#define f first
#define s second
#define int long long
using namespace std;
using ll = long long;
using ii = pair<int, int>;
constexpr int MX = 1005, M = 36;

ii P[MX];

main() {
	if (fopen("in", "r")) freopen("in", "r", stdin), freopen("out", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0);

	int N; cin >> N;
	for (int i = 0; i < N; ++i) cin >> P[i].f >> P[i].s;

	bool b = (P[0].f+P[0].s)&1;
	for (int i = 1; i < N; ++i) if ((P[i].f+P[i].s)&1^b) {
		cout << -1;
		return 0;
	}

	if (!b) {
		for (int i = 0; i < N; ++i) --P[i].f;
		cout << M+1 << '\n' << 1 << ' ';
	}
	else cout << M << '\n';
	for (int i = M-1; i >= 0; --i) cout << (1ll<<i) << ' ';
	cout << '\n';

	for (int j = 0; j < N; ++j) {
		if (!b) cout << 'R';

		int X = P[j].f, Y = P[j].s;

		for (int i = M-1; i >= 0; --i) {
			if (X > 0 && abs(Y) <= X) {
				cout << 'R';
				X -= (1ll<<i);
			}
			else if (X < 0 && abs(Y) <= -X) {
				cout << 'L';
				X += (1ll<<i);
			}
			else if (Y > 0 && abs(X) <= Y) {
				cout << 'U';
				Y -= (1ll<<i);
			}
			else {
				cout << 'D';
				Y += (1ll<<i);
			}
			//cout << X << ' ' << Y << '\n';
		}
		cout << '\n';
		//cout << X << ' ' << Y << '\n';
	}
}
