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
bool compare_by_a(pair<lint, lint> a, pair<lint, lint> b) {
	if (a.first != b.first) { return a.first < b.first; }
	else { return a.second < b.second; }
}
bool compare_by_a_bigger(pair<lint, lint> a, pair<lint, lint> b) {
	if (a.first != b.first) { return a.first < b.first; }
	else { return a.second < b.second; }
}
bool compare_by_b(pair<lint, lint> a, pair<lint, lint> b) {
	if (a.second != b.second) { return a.second < b.second; }
	else { return a.first < b.first; }
}
bool compare_by_b_bigger(pair<lint, lint> a, pair<lint, lint> b) {
	if (a.second != b.second) { return a.second > b.second; }
	else { return a.first > b.first; }
}

int main() {
	lint N{}, M{}, total{}, save{}, R{}; std::cin >> N >> M;
	std::vector<lint> A(N); for (auto& r : A) { std::cin >> r; total += r; }
	std::vector<std::pair<lint, lint>> B(M);
	for (auto& r : B) { std::cin >> r.second >> r.first; R += r.second; }
	std::sort(A.begin(), A.end());
	std::sort(B.begin(), B.end());
	lint j = 0; lint count{}, total_count{};
	for (int i = 0; i < N; ++i) {
		++total_count;
		if (count == B[M - 1 - j].second) { count = 0; ++j; }
		save = total;
		total = total - A[i] + B[M - 1 - j].first;
		A[i] = B[M - 1 - j].first;
		if (total < save) { std::cout << save << std::endl; return 0; }
		if (total_count == R) { break; }
		++count;
	}
	std::cout << total << std::endl;

	return 0;
}