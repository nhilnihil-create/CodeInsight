#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <list>
#include <ctime>
#include <complex>
#include <bitset>
#include <tuple>

#define IOS ios::sync_with_stdio(false);cin.tie(0)
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define MOD 1000000007LL
#define rep(i,a,n) for (int i=a ; i<n ; i++)
#define per(i,a,n) for (int i=n-1 ; i>=a ; i--)
#define LLINF (llong)1e18+5
#define INF 1e9+5

using namespace std;
using llong = long long;
using VI = vector<int>;
using VLL = vector<long long>;
using PII = pair<int, int>;

int n;
vector<int> cur;
vector<vector<vector<double>>> dp;
double dfs(int oneCnt, int twoCnt, int threeCnt)
{
	int cnt = oneCnt + twoCnt + threeCnt;
	if (cnt == 0) return 0;
	if (dp[oneCnt][twoCnt][threeCnt] != -1) return dp[oneCnt][twoCnt][threeCnt];
	double sum = 0;

	if(threeCnt > 0)
		sum += threeCnt * dfs(oneCnt, twoCnt + 1, threeCnt - 1);	
	if(twoCnt > 0)
		sum += twoCnt * dfs(oneCnt + 1, twoCnt - 1, threeCnt);
	if(oneCnt > 0)
		sum += oneCnt * dfs(oneCnt - 1, twoCnt, threeCnt);

	return dp[oneCnt][twoCnt][threeCnt] = (double)n / (double)cnt + (double)sum/(double)cnt;
}

int main()
{
	IOS;

	cin >> n;
	cur.resize(n);
	int one = 0, two = 0, three = 0;
	rep(i, 0, n)
	{
		cin >> cur[i];
		if (cur[i] == 1) one++;
		else if (cur[i] == 2)two++;
		else three++;
	}
	dp.resize(n+1);
	rep(i, 0, n+1) dp[i].resize(n+1);
	rep(i, 0, n + 1) rep(j, 0, n+ 1) dp[i][j].resize(n + 1), fill(all(dp[i][j]), -1);

	cout << fixed;
	cout << setprecision(16);
	cout << dfs(one, two, three);

	return 0;
}
