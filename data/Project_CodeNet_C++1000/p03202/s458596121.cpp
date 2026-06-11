#include <bits/stdc++.h>
#define debug(x) cerr << #x << " " << (x) << endl
using namespace std;

const int N = 200005, inf = 1000000005;

template <class T>
void read (T &x) {
	int sgn = 1;
	char ch;
	x = 0;
	for (ch = getchar(); (ch < '0' || ch > '9') && ch != '-'; ch = getchar()) ;
	if (ch == '-') ch = getchar(), sgn = -1;
	for (; '0' <= ch && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
	x *= sgn;
}

template <class T>
void write (T x) {
	if (x < 0) putchar('-'), write(-x);
	else if (x < 10) putchar(x + '0');
	else write(x / 10), putchar(x % 10 + '0');
}

int n, a[N];
map<int, int> m;

bool check (int mid) {
	m.clear();
	for (int i = 1, j = 0; i < n; i++) {
		if (a[i] <= a[i - 1]) {
			if (mid <= 1) return false;
			while (!m.empty() && m.rbegin() -> first > a[i]) m.erase(m.rbegin() -> first);
			m[a[i]]++;
			for (j = a[i]; j; j--) {
				if (m[j] < mid) break;
				m[j] = 0, m[j - 1]++;
			}
			if (!j) return false;
		}
	}
	return true;
}
int main () {
	read(n);
	for (int i = 0; i < n; i++) read(a[i]);
	int l = 1, r = inf;
	while (l < r) {
		int mid = l + r >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	write(l), putchar('\n');
	return 0;
}