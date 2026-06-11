#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int delta = 1e5;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
bool used[MAXN];
int n, l[MAXN], r[MAXN];
vector <int> hl[MAXN], hr[MAXN];
ll solve(int now, bool flg) {
	for (int i = 1; i <= n; i++) {
		used[i] = false;
		hl[l[i]].push_back(i);
		hr[r[i]].push_back(i);
	}
	ll ans = 0;
	int p = 0, q = 2e5;
	while (true) {
		if (flg) {
			while (q > now && (hl[q].empty() || used[hl[q].back()])) {
				while (q > now && hl[q].empty()) q--;
				while (q > now && !hl[q].empty() && used[hl[q].back()]) hl[q].pop_back();
			}
			if (q == now) break;
			ans += q - now, now = q;
			used[hl[q].back()] = true;
		} else {
			while (p < now && (hr[p].empty() || used[hr[p].back()])) {
				while (p < now && hr[p].empty()) p++;
				while (p < now && !hr[p].empty() && used[hr[p].back()]) hr[p].pop_back();
			}
			if (p == now) break;
			ans += now - p, now = p;
			used[hr[p].back()] = true;
		}
		flg ^= true;
	}
	return ans + abs(now - delta);
}
int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		read(l[i]), read(r[i]);
		l[i] += delta;
		r[i] += delta;
	}
	writeln(max(solve(delta, false), solve(delta, true)));
	return 0;
}