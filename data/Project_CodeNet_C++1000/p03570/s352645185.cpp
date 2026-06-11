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
const int N = 200005;
//////////////////////////////

string s;
int n;
vector<int> dp(N, INF);
vector<int> memo(1 << 26, INF);
int hor(int bit, int i)
{
	return bit ^ (1 << i);
}

void solve()
{
	cin >> s;
	n = s.size();
	dp[0] = 0;
	memo[0] = 0;
	int par = 0;
	RREP(i, n) {
		par = hor (par, s[i - 1] - 'a');
		dp[i] = min(dp[i], memo[par] + 1);
		REP(j, 26) {
			par = hor (par, j);
			dp[i] = min(dp[i], memo[par] + 1);
			par = hor (par, j);
		}
		memo[par] = min(memo[par], dp[i]);
	}
	cout << dp[n] << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(13);
	solve();
	return 0;
}

