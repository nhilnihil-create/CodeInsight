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
#include <cstdio>
#include <cstring>
#include <cmath>
#include <list>
#include <numeric>
#include <stack>
#include <iomanip>
#include <random>
#include <complex>
#include <functional>
#include <tuple>

using namespace std;

#define Rep(i,a,b) for(int i = a; i < b; ++i)
#define rep(i,b) Rep(i,0,b)
#define allof(a) (a).begin(), (a).end()

#define Yes(q) ((q) ? "Yes" : "No")
#define YES(q) ((q) ? "YES" : "NO")
#define Possible(q) ((q) ? "Possible" : "Impossible")
#define POSSIBLE(q) ((q) ? "POSSIBLE" : "IMPOSSIBLE")

using ll = long long;

using pint = std::pair<int, int>;
using pll = std::pair<ll, ll>;


constexpr int inf = 1e9 + 7;
constexpr ll infll = 1ll << 60ll;
constexpr ll mod = 1e9 + 7;
// 0~3までは右左下上 4~7までは斜め
constexpr int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
constexpr int dy[] = { 0, -1, 0, 1, 1, -1, -1, 1 };

namespace {
	template<typename T> void chmax(T& a, T b) { a = std::max(a, b); }
	template<typename T> void chmin(T& a, T b) { a = std::min(a, b); }
	template<typename T> void chadd(T& a, T b) { a = a + b; }

	void Cout(long long x, const char* end = "\n") { std::cout << x << end; }
	template <typename T> void Cout(const T& x, const char* end = "\n") { std::cout << x << end; }
	template <typename T> void Cout(const std::vector<T>& x, const char* sep = " ", const char* end = "\n") { for (std::size_t i = 0, sz = x.size(); i < sz; i++) { std::cout << x[i] << (i == sz - 1 ? end : sep); } }

	void CCout(long long x, const char* end = "\n") { std::cerr << x << end; }
	template <typename T> void CCout(const T& x, const char* end = "\n") { std::cerr << x << end; }
	template <typename T> void CCout(const std::vector<T>& x, const char* sep = " ", const char* end = "\n") { for (std::size_t i = 0, sz = x.size(); i < sz; i++) { std::cerr << x[i] << (i == sz - 1 ? end : sep); } }

	// 標準入出力
	struct inp {
		std::size_t sz;
		inp(std::size_t _sz = 1) : sz(_sz) {}
		template <typename T> operator T () const { T a; std::cin >> a; return a; }
		template <typename T> operator std::vector<T>() const { vector<T> a(sz); for (std::size_t i = 0; i < sz; i++) std::cin >> a[i]; return a; }
		template <typename T, typename U> operator std::pair<T, U>() const { T f; U s; std::cin >> f >> s; return std::pair<T, U>(f, s); }
	};

	inp inp1; // input one

	bool Has(int a, int i) {
		return (a & (1 << i));
	}
}

int main() {

	int n = inp1;
	vector<int> a = inp(n);

	// 100 xor 010 xor 001 = 100 + 010 + 001
	// 全てにおいて繰り上げが存在しない

	// じゃあ芋すほうで行ける？ 20

	// O(10^6)

	ll ans = 0;

	vector<int> num(21, 0);

	int right = 0;

	rep(left, n) {

		if (right < left) right = left;

		// 進める
		while (true) {

			if (right == n) break;

			// rightを伸ばせるか
			bool can = true;
			rep(bit, 21) {
				if (!num[bit]) continue;
				if (Has(a[right], bit)) {
					can = false;
					break;
				}
			}

			if (can) { // 伸ばせる
				ans += right - left + 1;

				cerr << "kita" << '\n';
				rep(bit, 21) {
					if (Has(a[right], bit)) ++num[bit];
				}
				right = min(right + 1, n);

				cerr << "left : " << left << " " << "right : " << right << '\n';
			}
			else { // 伸ばせない
				break;
			}
		}

		// 用済みなので消す
		rep(bit, 21) {
			if (Has(a[left], bit)) --num[bit];
		}
	}

	Cout(ans);

	return 0;
}