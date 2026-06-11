#pragma GCC optimize ("Ofast")
#include <cmath>
#include <functional>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>
#include <cstring>
	
#define int long long
#define double long double 
#define PI 3.141592653589793
#define FAST ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
// Use for file I/O;
#define FIN string _fname = "homework"; \
			string _is = _fname + ".in", _os = _fname + ".out"; \
			freopen(_is.c_str(), "r", stdin); \
			freopen(_os.c_str(), "w", stdout);

using namespace std;
	
int gcd(int a, int b) {
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

const int INF = 4e18 + 10;
const int INF2 = 2e18 + 10;
const int INF3 = 2e10;
const int MAXN = 303;
const int LOGN = 19;
const int MOD = 1e9 + 7;
const int EPS = 1e-9;
const int MULT = 2e5;
const int MCNST = MOD * MOD * 8;

int dp[101][100005];

int32_t main() {
	FAST;
	
	int n, k;
	cin >> n >> k;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			dp[i][j] = 0;
		}
	}

	vector<int> p(2*k + 5, 0);
	
	dp[0][0] = 1;
		
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		for (int j = 0; j <= k; j++) {
			p[j] += dp[i][j];
			p[j + a + 1] -= dp[i][j];
		}
		int cv = 0;
		for (int j = 0; j <= k; j++) {
			cv = (cv + 2*MOD + p[j]) % MOD;
			p[j] = 0;
			dp[i + 1][j] = cv;
		}
	}

	cout << dp[n][k];
}