
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

ll x[1000];
ll y[1000];
ll z[1000];

ll s[8][1000];

int main() {
	int N, M;
	cin >> N >> M;

	for (int i=0; i<N; i++) {
		cin >> x[i] >> y[i] >> z[i];
	}

	// 綺麗さ+ 美味しさ+ 人気度+
	for (int i=0; i<N; i++) {
		s[0][i] = x[i] + y[i] + z[i];
	}

	// 綺麗さ- 美味しさ+ 人気度+
	for (int i=0; i<N; i++) {
		s[1][i] = - x[i] + y[i] + z[i];
	}

	// 綺麗さ+ 美味しさ- 人気度+
	for (int i=0; i<N; i++) {
		s[2][i] = x[i] - y[i] + z[i];
	}

	// 綺麗さ+ 美味しさ+ 人気度-
	for (int i=0; i<N; i++) {
		s[3][i] = x[i] + y[i] - z[i];
	}

	// 綺麗さ- 美味しさ- 人気度+
	for (int i=0; i<N; i++) {
		s[4][i] = - x[i] - y[i] + z[i];
	}

	// 綺麗さ+ 美味しさ- 人気度-
	for (int i=0; i<N; i++) {
		s[5][i] = x[i] - y[i] - z[i];
	}

	// 綺麗さ- 美味しさ+ 人気度-
	for (int i=0; i<N; i++) {
		s[6][i] = - x[i] + y[i] - z[i];
	}

	// 綺麗さ- 美味しさ- 人気度-
	for (int i=0; i<N; i++) {
		s[7][i] = - x[i] - y[i] - z[i];
	}

	ll ans = 0;
	for (int i=0; i<8; i++) {
		ll m = 0;
		sort(s[i], s[i]+N, greater<ll>());

		for (int j=0; j<M; j++) {
			m += s[i][j];
		}

		ans = max(ans, m);
	}

	cout << ans << endl;

	return 0;
}