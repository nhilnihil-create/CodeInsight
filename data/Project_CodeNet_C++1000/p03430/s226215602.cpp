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
#include<list>
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
#define RREP(i,n) for(int i=1; i<=(int)(n); ++i)
#define FOR(i,k,n) for(int i=(k);i<(int)(n);++i)
typedef long long Int;
typedef pair<Int, Int> P;
typedef vector<double> vec;
typedef vector<vec> mat;
const int N = 100005;
//////////////////////////////

string s;
int k;
int dp[330][330][330];

void solve()
{
	cin >> s;
	cin >> k;
	int n = s.size();
	REP(i, n) REP(l, n) REP(x, k + 1) {
		int r = l + i;
		if (l > r || n <= r) continue;
		
		if (l == r) { dp[l][r][x] = 1; continue; }
		if (r - l + 1 <= 2 * x) { dp[l][r][x] = r - l + 1; continue; }
		if (s[l] == s[r]) dp[l][r][x] = dp[l + 1][r - 1][x] + 2;
		else if(x > 0) dp[l][r][x] = max(dp[l + 1][r - 1][x - 1] + 2, max(dp[l + 1][r][x], dp[l][r - 1][x]));
		else dp[l][r][x] = max(dp[l + 1][r][x], dp[l][r - 1][x]);
	}
	cout << dp[0][n - 1][k] << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(13);
	solve();
	return 0;
}

