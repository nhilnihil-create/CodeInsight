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
	int n;
	cin >> n;
	vector<bool> seen(n);
	vector<int> g[n], p(n), c(n);
	rep (i, n - 1) {
		int s, t;
		cin >> s >> t;
		g[s - 1].push_back(t - 1);
		g[t - 1].push_back(s - 1);
	}
	ll sum = 0;
	rep (i, n) cin >> c[i];
	sort(all(c), [](int a, int b) {return a > b;});
	repp (i, 1, n) sum += c[i];
	printf("%lld\n", sum);
	int start = -1, count = 0;
	rep (i, n) if (g[i].size() == 1) start = i;
	eprintf("start: %d\n", start);
	priority_queue<int> pq;
	pq.push(start);
	seen[start] = true;
	while (!pq.empty()) {
		int now = pq.top();
		pq.pop();
		eprintf("now:%d count:%d c[count]:%d\n", now, count, c[count]);
		p[now] = c[count++];
		for (int x : g[now]) {
			if (!seen[x]) pq.push(x);
			seen[x] = true;
		}
	}
	rep (i, n) printf("%d ", p[i]); printf("\n");
}