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

int dp[400][400];
int a[400], p[401];

int32_t main() {
	FAST;
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = INF;
		}
	}
	p[0] = 0;
	for (int i = 0; i < n; i++) {
		p[i + 1] = p[i] + a[i];
	}

	for (int i = 0; i < n; i++) {
		dp[i][i] = 0;
	}

	for (int l = 2; l <= n; l++) {
		for (int i = 0; i <= n - l; i++) {
			for (int j = i; j < i + l; j++) {
				dp[i][i + l - 1] = min(dp[i][i + l - 1], dp[i][j] + dp[j + 1][i + l - 1] + p[i + l] - p[i]);
			}
		}
	}
	cout << dp[0][n - 1];
}