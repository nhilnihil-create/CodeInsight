#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
int dp[100010] = { 0 };
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		dp[i] = 1000000007;
	}
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j *= 6) {
			if (i - j >= 0) {
				dp[i] = min(dp[i], dp[i - j] + 1);
			}
		}
		for (int j = 9; j <= n; j *= 9) {
			if (i - j >= 0) {
				dp[i] = min(dp[i], dp[i - j] + 1);
			}
		}
	}
	cout << dp[n] << endl;
	return 0;
}