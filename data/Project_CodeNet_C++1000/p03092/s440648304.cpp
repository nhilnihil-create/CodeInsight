 /*
ЗАПУСКАЕМ 
░ГУСЯ░▄▀▀▀▄░РАБОТЯГУ░░
▄███▀░◐░░░▌░░░░░░░
░░░░▌░░░░░▐░░░░░░░
░░░░▐░░░░░▐░░░░░░░
░░░░▐░░░░░▐░░░░░░░
░░░░▐░░░░░▐░░░░░░░
░░░░▐░░░░░▐░░░░░░░
░░░░▐░░░░░▐░░░░░░░
░░░░▐░░░░░▐░░░░░░░
░░░░▐░░░░░▐░░░░░░░
░░░░▐░░░░░▐░░░░░░░
░░░░▌░░░░░▐▄▄░░░░░
░░░░▌░░░░▄▀▒▒▀▀▀▀▄
░░░▐░░░░▐▒▒▒▒▒▒▒▒▀▀▄
░░░▐░░░░▐▄▒▒▒▒▒▒▒▒▒▒▀▄
░░░░▀▄░░░░▀▄▒▒▒▒▒▒▒▒▒▒▀▄
░░░░░░▀▄▄▄▄▄█▄▄▄▄▄▄▄▄▄▄▄▀▄
░░░░░░░░░░░▌▌░▌▌░░░░░
░░░░░░░░░░░▌▌░▌▌░░░░░
░░░░░░░░░▄▄▌▌▄▌▌░░░░░ 
 */
#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>

using namespace std;
template<typename T1, typename T2> inline void chkmin(T1 &a, T2 b) {if (a > b) a = b;}
template<typename T1, typename T2> inline void chkmax(T1 &a, T2 b) {if (a < b) a = b;}
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define left left228
#define right right228
#define y1 y1228
#define mp update_pair
#define pb push_back
#define y2 y2228
const string FILENAME = "input";
const int MAXN = 5005;


int n, a, b;
int p[MAXN];
long long dp[MAXN][MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
  	//read(FILENAME);
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			dp[i][j] = 1e18;
		}	
	}
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= n; j++) {
            if (p[i] < j) {
                chkmin(dp[i + 1][j], dp[i][j] + b);
            } else {
               	chkmin(dp[i + 1][p[i]], dp[i][j]);
                chkmin(dp[i + 1][j], dp[i][j] + a);
            }
		}
	}
	long long ans = 1e18;
	for (int i = 0; i <= n; i++) {
		chkmin(ans, dp[n][i]);
	}
	cout << ans << '\n';
	return 0; 	
}