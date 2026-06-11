
#include <bits/stdc++.h>

#define ln                '\n'
#define all(dat)           dat.begin(), dat.end()
#define loop(i, to)        for (int i = 0; i < to; ++i)
#define cont(i, to)        for (int i = 1; i <= to; ++i)
#define circ(i, fr, to)    for (int i = fr; i <= to; ++i)
#define foreach(i, dat)    for (__typeof(dat.begin()) i = dat.begin(); i != dat.end(); ++i)

typedef long long          num;

using namespace std;

const int nsz = 2e5;
int n, a[nsz + 5];

bool inline add_one(int fm, int mx, map<int, int> &d) {
	if (mx == 1)  return 0;
	for (int i = fm; i >= 1; --i) {
		if (d[i] < mx - 1) {
			++d[i];
			return 1;
		}
		d[i] = 0;
	}
	return 0;
}

bool inline chk(int mx) {
	map<int, int> d;
	cont (i, n) {
		int cur = a[i], pre = a[i - 1];
		if (cur > pre) {
			d[cur] = 0;
		} else {
			if (!add_one(cur, mx, d))  return 0;
		}
		d.erase(d.upper_bound(cur), d.end());
	}
	return 1;
}

int inline solve() {
	int l = 0, r = n + 1, md = (l + r) >> 1;
	for (; r - l > 1; md = (l + r) >> 1) {
		(chk(md) ? r : l) = md;
	}
	return r;
}

int inline read() {
	int res = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar());
	for (; isdigit(c); res *= 10, res += c ^ 48, c = getchar());
	return res;
}

void inline write(int a, char c) {
	int s = 0, d[10] = {0};
	for (; a; d[s++] = a % 10, a /= 10);
	for (s = s ? s : 1; s; putchar(d[--s] + 48));
}

int main() {
	n = read();
	cont (i, n) {
		a[i] = read();
	}
	write(solve(), ln);
}