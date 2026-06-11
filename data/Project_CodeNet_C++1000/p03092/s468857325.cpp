	//     . .. ... ..... be naame khodaa ..... .... ... .. .     \\

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

inline int in(){int x, y; y = scanf("%d", &x); return x;}

const int N = 5005;
const ll INF = 1e18;

ll dp[N][N], best[N];
int p[N], q[N];

int main() {
	int n = in();
	ll R = in(), L = in();
	for(int i = 1; i <= n; i++) {
		q[p[i] = in()] = i;
	}
	for(int j = 0; j <= n; j++) {
		dp[0][j] = j*R;
	}
	fill(best, best + n + 1, INF);
	best[0] = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= n; j++) {
			int pos = q[i];
			ll &res = dp[i][j];
			res = INF;
			if(j >= pos - 1)
				res = dp[i - 1][j];
			if(j) {
				if(p[j] <= i)
					res = min(res, dp[i][j - 1]);
				if(p[j] == i)
					res = min(res, dp[i - 1][j - 1]);
				res = min(res, dp[i][j - 1] + R);
			}
			res = min(res, dp[i - 1][j] + L);
			//res = min(min(dp[i - 1][pos - 1], best[i - 1] + L), res);
			best[i] = min(best[i], dp[i][j]);
//			cerr << i << ", " << j << ": " << res << endl;
		}
	cout << best[n] << endl;
}
