#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <deque>
#include <bitset>
using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
using ll = long long;
int dp[1100000];


int main() {
	int n;
	cin >> n;
	for (int i=0; i<=1000000; i++) dp[i] = 10000000;

	dp[0] = 0;
	rep(i, 1000000) {
		dp[i+1] = min(dp[i]+1, dp[i+1]);

		for (int j=6; i+j<=1000000; j*=6) {
			dp[i+j] = min(dp[i+j], dp[i]+1);
		}
		for (int j=9; i+j<=1000000; j*=9) {
			dp[i+j] = min(dp[i+j], dp[i]+1);
		}
	}
	cout << dp[n] << endl;
}