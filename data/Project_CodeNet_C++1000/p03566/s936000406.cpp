#include <cstdio>
#include <random>
#include <cassert>
#include <algorithm>    
#include <iostream>
#include <chrono>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <bitset>
#define pb push_back
#define mk make_pair
#define eb emplace_back
#define eps 1e-8
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
// #define int long long


using namespace std;
typedef long double ld;
typedef unsigned int ui;
typedef pair<int,int> pii;
typedef tuple<int, int, int> tiii;
typedef vector<int> vii;
typedef vector<long double> vd;
const int inf = 1e9;
const long long INF = 1e18;
const int M = 1e9 + 7;





signed main()
{
#ifndef ONLINE_JUDGE
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
#endif
	int n;
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	int tot = 0;
	const int maxn = 50000;
	static int num[maxn];
	static double dp[maxn][400];
	static bool vis[maxn][400];
	int t[202], v[202];
	for(int i = 0; i < n; ++i) {
		cin >> t[i];
		for(int j = tot + 1; j <= tot + 2 * t[i]; ++j) {
			num[j] = i;
		}
		tot += 2 * t[i];
	}
	for(int i = 0; i < n; ++i) {
		cin >> v[i];
		v[i] *= 2;
	}	
	vis[0][0] = 1;
	dp[0][0] = 0;
	for(int i = 0; i < tot; ++i) {
		int k = num[i];
		for(int j = 0; j <= v[k]; ++j) {
			if(vis[i][j]) {
				int tk = num[i + 1];
				if(j + 1 <= v[tk]) {
					dp[i + 1][j + 1] =  max(dp[i + 1][j + 1], dp[i][j] + (j + j + 1) / 2.);
					vis[i + 1][j + 1] = 1;
				}
				if(j <= v[tk]) {
					dp[i + 1][j] = max(dp[i][j] + j, dp[i + 1][j]);
					vis[i + 1][j] = 1;
				}
				if(j > 0 && j <= v[tk]) {
					dp[i + 1][j - 1] = max(dp[i + 1][j - 1], dp[i][j] + (j + j - 1) / 2.);
					vis[i + 1][j - 1] = 1;
				}
			}
		}
	}
	printf("%.5f\n", dp[tot][0] / 4);


    
	return 0;
}