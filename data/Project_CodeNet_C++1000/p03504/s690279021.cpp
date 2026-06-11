#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <math.h>
#include <deque>
#include <queue>
#include <map>
#include <iterator>
#include <set>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using Pll = pair<ll, ll>;
#define debug(var)  do{std::cout << #var << " : ";view(var);}while(0)
template<typename T> void view(T e) { std::cout << e << std::endl; }
template<typename T> void view(const std::vector<T>& v) { for (const auto& e : v) { std::cout << e << " "; } std::cout << std::endl; }
template<typename T> void view(const std::vector<std::vector<T> >& vv) { for (const auto& v : vv) { view(v); } }
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

const int mxN = 1e5 + 6;
const int mxC = 32;
int s[mxN], t[mxN], c[mxN];
vector<int> sum(mxN * mxC + 5);
vector<int> cnt(mxN * mxC + 5, 0);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, C;
	cin >> n >> C;
	for (int i = 0; i < n; i++) {
		cin >> s[i] >> t[i] >> c[i];
	}
	for (int i = 1; i <= C; i++) {
		for (int j = 0; j < (int)sum.size(); j++) {
			sum[j] = 0;
		}
		for (int j = 0; j < n; j++) {
			if (c[j] == i) {
				sum[s[j] * 2 - 1]++, sum[t[j] * 2]--;
			}
		}
		for (int j = 0; j < (int)sum.size() - 1; j++) {
			sum[j + 1] = sum[j + 1] + sum[j];
		}
		for (int j = 0; j < (int)sum.size(); j++) {
			if (sum[j] > 0) cnt[j]++;
		}
	}

	int mx = 0;
	for (int i = 0; i < (int)cnt.size(); i++) {
		chmax(mx, cnt[i]);
	}
	cout << mx << endl;
}