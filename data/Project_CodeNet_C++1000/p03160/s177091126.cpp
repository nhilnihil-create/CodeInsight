#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <functional>
#include <cmath>
#define REP(i,n) for(lint i{}, i##_len=(n); i<i##_len; ++i)
#define DOUBLE_LOOP(i, h, j, w) for(lint i{}; i < (lint)(h); ++i)for(lint j{}; j < (lint)(w); ++j)
#define DOUBLE_LOOP2(i, j, n) for(lint i{}; i < (lint)(n - 1); ++i)for(lint j{i + 1}; j < (lint)(n); ++j)
#define SZ(x) ((lint)(x).size())
using lint = long long; lint N, H, W;
using namespace std;
const long long INF{ 1LL << 60 };
const long double PI{ 3.1415926535897932 };
const long long NUM97{ 1000000007 };
template<class T> inline bool chmax(T& x, T y) { if (x < y) { x = y; return 1; } return 0; }
template<class T> inline bool chmin(T& x, T y) { if (x > y) { x = y; return 1; } return 0; }
std::vector<std::string> field;
std::vector<std::vector<bool>> seen(H, std::vector<bool>(W));
const std::vector<int> dx { 1, 0, -1, 0 };
const std::vector<int> dy { 0, 1, 0, -1 };
std::vector<lint> dp;
std::vector<lint> h;
int main(){
	std::cin >> N;
	h.resize(N); for(auto& r : h) std::cin >> r;
	dp.resize(N);  for (auto& r : dp) r = INF;
	dp[0] = 0;
	for (int i = 1; i < N; ++i) {
		chmin(dp[i], dp[i - 1] + std::abs(h[i] - h[i - 1]));
		if (i > 1) { chmin(dp[i], dp[i - 2] + std::abs(h[i] - h[i - 2])); }
	}
	std::cout << dp[N - 1] << std::endl;
	return 0;
}