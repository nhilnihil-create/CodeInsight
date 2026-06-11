#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define INF_LL (ll)1e18
#define INF (int)1e9
#define REP(i, n) for(int i = 0;i < (n);i++)
#define FOR(i, a, b) for(int i = (a);i < (b);i++)
#define all(x) x.begin(),x.end()
using ll = long long;
using PII = pair<int, int>;

const double eps = 1e-10;

template<typename A, typename B>inline void chmin(A &a, B b){if(a > b) a = b;}
template<typename A, typename B>inline void chmax(A &a, B b){if(a < b) a = b;}

string s;
int a[214514] = {};
int dp[214514] = {};
int dp2[1<<26] = {};

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> s;
	REP(i, s.size()){
		a[i+1] = a[i]^(1 << (s[i]-'a'));
	}
	fill(dp, dp+214514, INF);
	fill(dp2, dp2+(1 << 26), INF);
	dp[0] = 0;
	dp2[0] = 0;
	FOR(i, 1, s.size()+1){
		dp[i] = min(dp[i], dp2[a[i]]+1);
		REP(j, 26){
			dp[i] = min(dp[i], dp2[a[i]^(1 << j)]+1);
		}
		dp2[a[i]] = min(dp2[a[i]], dp[i]);
	}
	cout << dp[s.size()] << endl;
}
