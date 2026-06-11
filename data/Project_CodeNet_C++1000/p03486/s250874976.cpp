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
#define DBLOOP(i, h, j, w) for(lint i{}; i < (lint)(h); ++i)for(lint j{}; j < (lint)(w); ++j)
#define DBLOOP2(i, j, n) for(lint i{}; i < (lint)(n - 1); ++i)for(lint j{i + 1}; j < (lint)(n); ++j)
#define SZ(x) ((lint)(x).size())
using lint = long long; lint N, M, H, W;
using Graph = std::vector<std::vector<lint>>;
using namespace std;
const long long INF{ 1LL << 60 };
const long long inf{ 1LL << 24 };
const long double PI{ 3.1415926535897932 };
const long long NUM97{ 1000000007 };
template<class T> inline bool chmax(T& x, T y) { if (x < y) { x = y; return 1; } return 0; }
template<class T> inline bool chmin(T& x, T y) { if (x > y) { x = y; return 1; } return 0; }
std::vector<std::string> field;
std::vector<std::vector<bool>> seen(H, std::vector<bool>(W));
const std::vector<int> dx{ 1, 0, -1, 0 };
const std::vector<int> dy{ 0, 1, 0, -1 };

int main() {
	std::string s, t; std::cin >> s >> t;
	std::sort(s.begin(), s.end());
	std::sort(t.begin(), t.end()); std::reverse(t.begin(), t.end());
	bool flag = false;
	for (int i = 0; i < std::min(s.size(), t.size()); ++i) {
		if (s[i] > t[i]) {
			std::cout << "No" << std::endl;
			return 0;
		}
		if (s[i] < t[i]) {
			flag = true;
			break;
		}
	}
	if (s.size() >= t.size() && flag == false) {
		std::cout << "No" << std::endl;
		return 0;
	}
	std::cout << "Yes" << std::endl;

	return 0;
}