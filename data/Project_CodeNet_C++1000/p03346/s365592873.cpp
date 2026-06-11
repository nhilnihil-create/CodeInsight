#include <bits/stdc++.h>
#define R register
#define mp make_pair
#define ll long long
#define pii pair<int, int>
using namespace std;
const int N = 210000;

int n, a[N], p[N];

template <class T>
inline void read(T &x) {
	x = 0;
	char ch = getchar(), w = 0;
	while (!isdigit(ch)) w = (ch == '-'), ch = getchar();
	while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	x = w ? -x : x;
	return;
}

int main() {
	read(n);
	for (R int i = 1; i <= n; ++i) read(a[i]), p[a[i]] = i;
	int ans = 0, now = 1;
	for (R int i = 1; i <= n; ++i) {
		if (!--now) {
			int lst = 0;
			while (i + now <= n && p[i + now] > lst) lst = p[i + now], ++now;
			ans = max(ans, now);
		}
	}
	cout << n - ans << endl;
	return 0;
}