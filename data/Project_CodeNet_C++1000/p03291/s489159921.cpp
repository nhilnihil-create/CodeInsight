#define _USE_MATH_DEFINES
#include<cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <iterator>
#include<iomanip>

using namespace std;

#define rep(i,a,b) for(int i=(a), i##_len=(b);i<i##_len;i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)

#define int ll
#define SZ(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

typedef long long ll;
//typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<double, double> pdd;
typedef vector<vector<int>> mat;
//typedef unsigned int uint;

template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;

int dp[100010][4];

signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	string S;

	cin >> S;
	dp[0][0] = 1;
	rep(i, 0, SZ(S))
	{
		if (S[i] == '?' || S[i] == 'A')
		{
			dp[i + 1][0] += dp[i][0];
			dp[i + 1][1] += dp[i][1];
			dp[i + 1][2] += dp[i][2];
			dp[i + 1][3] += dp[i][3];
			dp[i + 1][1] += dp[i][0];
		}
		if (S[i] == '?' || S[i] == 'B')
		{
			dp[i + 1][0] += dp[i][0];
			dp[i + 1][1] += dp[i][1];
			dp[i + 1][2] += dp[i][2];
			dp[i + 1][3] += dp[i][3];
			dp[i + 1][2] += dp[i][1];
		}
		if (S[i] == '?' || S[i] == 'C')
		{
			dp[i + 1][0] += dp[i][0];
			dp[i + 1][1] += dp[i][1];
			dp[i + 1][2] += dp[i][2];
			dp[i + 1][3] += dp[i][3];
			dp[i + 1][3] += dp[i][2];
		}
		rep(j, 0, 4)dp[i + 1][j] %= MOD;
	}

	cout << dp[SZ(S)][3] << endl;

	return 0;
}