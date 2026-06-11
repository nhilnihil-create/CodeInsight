#include <bits/stdc++.h>
using namespace std;
#define ri rd<int>
#define rep(i, a, b) for (int i = (a), _ = (b); i <= _; ++i)
#define per(i, a, b) for (int i = (a), _ = (b); i >= _; --i)
#define For(i, a, b) for (int i = (a), _ = (b); i < _; ++i)
typedef long long LL;
typedef long double db;

template<class T> inline T rd() {
	bool f = 1; char c = getchar(); for (; !isdigit(c); c = getchar()) if (c == '-') f = 0;
	T x = 0; for (; isdigit(c); c = getchar()) x = x * 10 + c - '0'; return f ? x : -x;
}

LL sum(LL s) {
	LL res = 0;
	for (; s; s /= 10) res += s % 10;
	return res;
}

db eval(LL x) {
	return (db)x / sum(x);
}

int main() {

	vector<LL> v;
	LL las = 1;
	for (int i = 1; i <= 14; ++i, las *= 10) {
		rep (i, 1, 99999) v.push_back((i+1) * las - 1);
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	vector<LL> stk;
	for (LL x : v) {
		while (!stk.empty() && eval(stk.back()) > eval(x)) stk.pop_back();
		stk.push_back(x);
	}

	For (i, 0, ri()) printf("%lld\n", stk[i]);

	return 0;
}
