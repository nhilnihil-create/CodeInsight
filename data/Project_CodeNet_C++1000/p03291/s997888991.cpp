#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime> 
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>
 
using namespace std;

const int N = 1e5 + 7;
const int MOD = 1e9 + 7;
const string need = "ABC";

int add(int a, int b) {
	return (a + b) % MOD;
}

int dp[N][4];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	cin >> s;
	int n = (int)s.size();
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			for (char c = 'A'; c <= 'C'; c++) {
				if (s[i] != '?' && s[i] != c) continue;
				dp[i + 1][j] = add(dp[i + 1][j], dp[i][j]);
				if (j < 3 && c == need[j]) {
					dp[i + 1][j + 1] = add(dp[i + 1][j + 1], dp[i][j]);
				}
			}
		}
	}
	cout << dp[n][3] << endl; 
}