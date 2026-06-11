#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 21, M = 1e9 + 7;

int a[N + 1][N], dp[N+1][1 << N];

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j < n; j++)
			cin >> a[i][j];
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < (1 << n); j++) {
			if(__builtin_popcount(j) != i) continue;
			for(int k = 0; k < n; k++) {
				if((j >> k & 1) && a[i][k]) {
					dp[i][j] = (dp[i][j] + dp[i - 1][j ^ (1 << k)]) % M;
				}
			}
		}
	}
	cout << dp[n][(1 << n) - 1] << endl;

}

