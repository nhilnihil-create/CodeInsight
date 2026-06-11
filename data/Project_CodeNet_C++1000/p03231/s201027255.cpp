#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <sstream>
#include <stdio.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <list>
#include <numeric>
#include <stack>
#include <iomanip>

//using namespace std;

#define Rep(i,a,b) for(int i = a; i < b; ++i)
#define rep(i,b) Rep(i,0,b)
#define allof(a) (a).begin(), (a).end()

typedef long long ll;
const int inf = 1e9 + 7;
const ll infll = 1ll << 60ll;
const ll mod = 1e9 + 7;
// 0~3までは右左下上 4~7までは斜め
constexpr int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
constexpr int dy[] = { 0, -1, 0, 1, 1, -1, -1, 1 };

template<typename T> void chmax(T& a, T b) { a = std::max(a, b); }
template<typename T> void chmin(T& a, T b) { a = std::min(a, b); }
template<typename T> void chadd(T& a, T b) { a = a + b; }

namespace {  // 名前なし名前空間
	// gcd, lcm は C++17 でstdに標準入りしたので言語のバージョンに注意
	// 最大公約数
	ll gcd(ll a, ll b) {
		if (b == 0) return a;
		return gcd(b, a % b);
	}

	// 最小公倍数
	ll lcm(ll a, ll b) {
		return a / gcd(a, b) * b;
	}
}

using namespace std;

int main() {

	int N, M;
	cin >> N >> M;
	string S, T;
	cin >> S >> T;
	long L = lcm(N, M);

	int g = 1;
	for (int i = min(N, M); i > 0; i--) {
		if (N % i == 0 && M % i == 0) {
			g = i;
			break;
		}
	}
	int n = N / g;
	int m = M / g;
	for (int i = 0; i < g; i++) {
		if (S.substr(i * n, 1) != T.substr(i * m, 1)) {
			cout << -1 << endl;
			return 0;
		}
	}
	cout << L << endl;

	return 0;
}