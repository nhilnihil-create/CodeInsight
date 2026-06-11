#include<bits/stdc++.h>
typedef long long ll ;
#define rep(i, a, b) for (int i = a; i <= b; ++i)
using namespace std;

template <typename tn> void read (tn & a) {
	tn x = 0, f = 1; char c = getchar();
	while (c < '0' || c > '9'){ if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9'){ x = x * 10 + c - '0'; c = getchar(); }
	a = f == 1 ? x : -x;
}

const int MAXN = 101000;
pair<ll, ll> x[MAXN];
ll n, ans, c;
ll sl[MAXN], sr[MAXN];
ll lm[MAXN], rm[MAXN];

int main() {
	read(n);
	read(c);
	rep(i, 1, n) read(x[i].first), read(x[i].second);
	sort(x + 1, x + 1 + n);
//	ll s = 0;
	ans = 0;
	rep(i, 1, n) {
		sl[i] = sl[i - 1] + x[i - 1].first - x[i].first + x[i].second;
		ans = max(ans, sl[i]);
		lm[i] = max(lm[i - 1], sl[i] - x[i].first);
	}
	sr[n + 1] = -c;
	for (int i = n; i >= 1; --i) {
		sr[i] = sr[i + 1] - x[i + 1].first + x[i].first + x[i].second;
		ans = max(ans, sr[i]);
		rm[i] = max(rm[i + 1], sr[i] - c + x[i].first);
		ans = max(ans, sr[i] + lm[i - 1]);
	}
	rep(i, 1, n) {
		ans = max(ans, sl[i] + rm[i + 1]);
	}
	cout << ans << "\n";
	return 0;
}
