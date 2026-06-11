#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
#include <stack>
#include <functional>

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; ++i)
#define repp(i, m, n) for(ll i = m, i##_len = (n); i < i##_len; ++i)
#define reprev(i, n) for(ll i = (n-1LL); i >= 0; --i)
#define all(x) (x).begin(), (x).end()
template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> P;
typedef long double ld;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, ans = 0;
	cin >> n;
	vector<int> a(n);
	rep (i, n) cin >> a[i];
	sort(all(a)/*, [](int a, int b) {return a > b;}*/);
	// rep (i, n) eprintf("%d ", a[i]); eprintf("\n");
	vector<bool> used(n);
	reprev (i, n) {
		if (used[i]) continue;
		used[i] = true;
		int k = 0, tmp = a[i];
		while (tmp != 0) {
			tmp >>= 1;
			k++;
		}
		tmp = (1 << k) - a[i];
		eprintf("%d+%d=2^n\n", a[i], tmp);
		auto p = equal_range(all(a), tmp);
		int ng = min((int)i, (int)distance(a.begin(), p.second) - 1);
		while (ng > 0 && a[ng - 1] == tmp && used[ng]) ng--;
		if (ng >= 0 && a[ng] == tmp && !used[ng]) {
			eprintf("(%lld,%d)\n", i, ng);
			ans++;
			used[ng] = true;
		}
	}
	cout << ans << "\n";
	return 0;
}