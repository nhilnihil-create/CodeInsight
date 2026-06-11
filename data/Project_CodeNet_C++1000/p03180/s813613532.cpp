#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include <cstring>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P; 
const int N = 1000006;
//////////////////////////////

Int n;
Int a[20][20];
Int dp[1 << 16];
Int cost[1 << 16];

int main() { 
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	for (int s = 0; s < (1 << n); s++) {
		for (int i = 0; i < n; i++) {
			if ((s >> i) % 2 == 0)continue;
			for (int j = i + 1; j < n; j++) {
				if ((s >> j) % 2 == 0)continue;
				cost[s] += a[i][j];
			}
		}
	}

	dp[0] = 0;
	for (int s = 1; s < (1 << n); s++) {
		for (int t = s; t > 0; t = (t - 1) & s) {
			dp[s] = max(dp[s], dp[s - t] + cost[t]);
		}
	}

	cout << dp[(1 << n) - 1] << endl;

	return 0;
}