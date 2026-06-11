#include<bits/stdc++.h>
#define _for(i, a, b) for(int i = (a);i < (b); ++i)
#define _rep(i, a, b) for(int i = (a);i <= (b); ++i)
#define b_e(a) begin(a), end(a)
#define ms(a, b) memset(a, b, sizeof(a))
#define mp make_pair
using namespace std;

typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pLL;
typedef pair<int, string> pis;

//int nextInt() { int x; scanf("%d", &x); return x; }
LL nextLL() { LL x; scanf("%lld", &x); return x; }
//double nextDouble() { double x; scanf("%lf", &x); return x; }
//string nextString() { string s; cin >> s; return s; }
//auto cmp = [](const int& a, const int& b) {return a > b;};
const int INF = 1e9;
const int MAXN = 100000;
const int dx[4] = { 0, 0, 1, -1 };
const int dy[4] = { 1, -1, 0, 0 };
vector<pLL> a;
LL sum[MAXN + 10];
LL rsum[MAXN + 10];
LL max1[MAXN + 10];
LL max2[MAXN + 10];
int main() {
	LL n = nextLL(), c = nextLL();
	_for(i, 0, n) {
		LL x = nextLL(), y = nextLL();
		a.emplace_back(x, y);
	}
	sort(b_e(a));
	_for(i, 0, n) {
		sum[i + 1] = sum[i] + a[i].second;
		rsum[n - i - 1] = rsum[n - i] + a[n - i - 1].second;
	}
	_for(k, 0, n) {
		int i = n - k - 1;
		max1[i] = max(max1[i + 1], rsum[i] - (c - a[i].first));
		max2[i] = max(max2[i + 1], rsum[i] - (c - a[i].first) * 2);
	}
	LL ans = 0;
	_for(i, 0, n) {
		LL temp = sum[i + 1] - a[i].first;
		ans = max(ans, temp);
		ans = max(ans, max1[i]);
		ans = max(ans, temp - a[i].first + max1[i + 1]);
		ans = max(ans, temp + max2[i + 1]);
	}
	printf("%lld", ans);
}