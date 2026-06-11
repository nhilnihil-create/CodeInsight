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
#include<unordered_map>
#include<unordered_set>
#include<bitset>
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
typedef pair<Int, Int> PI;
typedef pair<int, int> P;
typedef vector<double> vec;
typedef vector<vec> mat;
const int N = 200005;
//////////////////////////////

int n;
int c[N];
Int dp[N];
Int sum[N];

void solve()
{
	cin >> n;
	RREP(i, n) cin >> c[i];

	dp[0] = 1;
	dp[1] = 1;
	sum[c[1]] = 1;
	for (int i = 2; i <= n; i++) {
		if (c[i] == c[i - 1]) {
			dp[i] = dp[i - 1];
		}
		else {
			dp[i] = (dp[i - 1] + sum[c[i]]) % MOD;
			sum[c[i]] = dp[i];
		}	
	}
	cout << dp[n] % MOD << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(13);
	solve();
	return 0;
}
