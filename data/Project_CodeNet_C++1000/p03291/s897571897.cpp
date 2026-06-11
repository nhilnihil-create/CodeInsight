#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <functional>
#include <climits>
#include <cstring>
#include <cmath>
#include <numeric>
#include <iomanip>

using namespace std;

#define int long long

#define rep(i, n) for (int i=0;i<(int)n;++i)
#define rep1(i, n) for (int i=1;i<=(int)n;++i)
#define rrep(i, n) for (int i=(int)n-1;i>=0;--i)
#define rrep1(i, n) for (int i=n;i>=1;--i)
#define range(i, l, r) for (int i=l;i<(int)r;++i)
#define rrange(i, l, r) for (int i=(int)r-1;i>=(int)l;--i)
#define unless(a) if(!(a))
#define all(a) begin(a),end(a)
#define fst first
#define scd second
#define PB emplace_back
#define PPB pop_back

using ll=long long;
using vi=vector<int>;
using pii=pair<int, int>;
using ld=long double;

bool chmin(int&a,int b){return a>b?(a=b,true):false;}
bool chmax(int&a,int b){return a<b?(a=b,true):false;}
constexpr int TEN(int n){return n==0?1:10*TEN(n-1);}

const int mod = TEN(9)+7;
const int inf = TEN(18) * 3 + 10;

const int B = mod;

string S;
int dp[100010][4];

signed main()
{
	cin >> S;
	int n = S.size();

	S = ' ' + S;

	dp[0][0] = 1;

	rep1(i, n) {
		if (S[i] == '?') {
			rep(j, 3) {
				(dp[i][j + 1] += dp[i - 1][j]) %= mod;
			}
			rep(j, 4) (dp[i][j] += dp[i - 1][j] * 3) %= mod;
		} else {
			rep(j, 4) (dp[i][j] += dp[i - 1][j]) %= mod;
			if (S[i] == 'A') {
				(dp[i][1] += dp[i - 1][0]) %= mod;
			}
			if (S[i] == 'B') {
				(dp[i][2] += dp[i - 1][1]) %= mod;
			}
			if (S[i] == 'C') {
				(dp[i][3] += dp[i - 1][2]) %= mod;
			}
		}
	}

	cout << dp[n][3] << endl;
}

