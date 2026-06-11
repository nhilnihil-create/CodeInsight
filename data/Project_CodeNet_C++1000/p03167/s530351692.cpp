#include <iostream>
#include <numeric>
#include <cmath>
#include <limits>
#include <stdio.h>
#include <iomanip>
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
using namespace std;
using ll = long long;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
ll Max(ll(a), ll(b), ll(c)) {
	return max(max(a, b), c);
}
ll Min(ll(a), ll(b), ll(c)) {
	return min(min(a, b), c);
}


ll mod = 1e9 + 7;

ll dp[1002][1002];
bool ma[1002][1002];
int main() {
	ll H, W;
	cin >> H >> W;
	rep(i, H) {
		string S;
		cin >> S;
		rep(j, W) {
			if (S.at(j) == '#')ma[i][j] = false;
			else ma[i][j] = true;
		}
	}
	dp[0][0] = 1;
	rep(i, H) {

		rep(j, W) {
			if (i == 0 && j == 0)continue;
			
			if (ma[i][j]) {
				if (i == 0) {
					dp[i][j] = dp[i][j-1];
				}
				else if (j == 0) {
					dp[i][j] = dp[i - 1][j];
				}
				else {
					dp[i][j] = dp[i - 1][j]+ dp[i][j-1];
				}
			}
			else {
				dp[i][j] = 0;
			}
			dp[i][j] %= mod;
		}
	}

	cout << dp[H - 1][W - 1] << endl;
}
