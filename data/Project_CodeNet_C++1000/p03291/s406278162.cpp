#include<iostream>
#include<iomanip>
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
#include <functional>
//#include<unordered_map>
//#include<unordered_set>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF ((Int)1<<60)
#define EPS (1e-10)
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
#define FOR(i,k,n) for(int i=(k);i<(int)(n);++i)
typedef long long Int;
typedef pair<Int, Int> P; 
typedef vector<double> vec;
typedef vector<vec> mat;
const int N = 200005;
//////////////////////////////

Int dp[N][4];

void solve()
{
	string s;
	cin >> s;
	int n = s.size();

	dp[0][3] = 1;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'A') {
			dp[i + 1][0] = (dp[i][0] + dp[i][3]);
			dp[i + 1][1] = dp[i][1];
			dp[i + 1][2] = dp[i][2];
		}
		if (s[i] == 'B') {
			dp[i + 1][0] = dp[i][0];
			dp[i + 1][1] = dp[i][0] + dp[i][1];
			dp[i + 1][2] = dp[i][2];
		}
		if (s[i] == 'C') {
			dp[i + 1][0] = dp[i][0];
			dp[i + 1][1] = dp[i][1];
			dp[i + 1][2] = dp[i][1] + dp[i][2];
		}
		if (s[i] == '?') {
			//A
			dp[i + 1][0] += (dp[i][0] + dp[i][3]);
			dp[i + 1][1] += dp[i][1];
			dp[i + 1][2] += dp[i][2];

			//B
			dp[i + 1][0] += dp[i][0];
			dp[i + 1][1] += dp[i][0] + dp[i][1];
			dp[i + 1][2] += dp[i][2];

			//C
			dp[i + 1][0] += dp[i][0];
			dp[i + 1][1] += dp[i][1];
			dp[i + 1][2] += dp[i][1] + dp[i][2];	
		}

		if(s[i] == '?') dp[i + 1][3] = (dp[i][3] * 3) % MOD;
		else dp[i + 1][3] = dp[i][3];

		for (int j = 0; j < 3; j++) dp[i + 1][j] %= MOD;
	}

	cout << dp[n][2] << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(13);
	solve();
	return 0;
}
