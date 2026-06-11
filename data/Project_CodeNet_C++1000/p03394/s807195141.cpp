#include <bits/stdc++.h>

typedef long long LL;

#define FOR(i, a, b) for (int i = (a), i##_END_ = (b); i <= i##_END_; i++)
#define DNF(i, a, b) for (int i = (a), i##_END_ = (b); i >= i##_END_; i--)

template <typename Tp> void in(Tp &x) {
	char ch = getchar(), f = 1; x = 0;
	while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
	if (ch == '-') ch = getchar(), f = -1;
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	x *= f;
}

template <typename Tp> void out(Tp x) {
	if (x > 9) out(x / 10);
	putchar(x % 10 + '0');
	return;
}

template <typename Tp> Tp Max(const Tp &x, const Tp &y) {return x > y ? x : y;}
template <typename Tp> Tp Min(const Tp &x, const Tp &y) {return x < y ? x : y;}
template <typename Tp> bool chkmax(Tp &x, Tp y) {return x >= y ? 0 : (x=y, 1);}
template <typename Tp> bool chkmin(Tp &x, Tp y) {return x <= y ? 0 : (x=y, 1);}

int n;
int ans[30010], sum;

void print() {
	FOR(i, 1, ans[0]) printf("%d ", ans[i]);
	putchar(10);
	exit(0);
}

int main()
{
	in(n);

	if (n == 3) {puts("2 5 63"); return 0;}

	while (true) {
		ans[0] = 0; sum = 0;
		FOR(i, 1, 30000) if (ans[0] < n && rand() % 5 < 5 && (i % 2 == 0 || i % 3 == 0)) {
			if (ans[0] == n - 1 && (sum + i) % 6 == 0) {
				ans[++ans[0]] = i; print();
			}
			else if (ans[0] != n - 1) {
				ans[++ans[0]] = i; sum += i;
			}
		}
		ans[0] = 0; sum = 0;
		FOR(i, 1, 30000) if (ans[0] < n && rand() % 5 < 5 && (i % 3 == 0 || i % 5 == 0)) {
			if (ans[0] == n - 1 && (sum + i) % 15 == 0) {
				ans[++ans[0]] = i; print();
			}
			else if (ans[0] != n - 1) {
				ans[++ans[0]] = i; sum += i;
			}
		}
		ans[0] = 0; sum = 0;
		FOR(i, 1, 30000) if (ans[0] < n && rand() % 5 < 5 && (i % 2 == 0 || i % 5 == 0)) {
			if (ans[0] == n - 1 && (sum + i) % 10 == 0) {
				ans[++ans[0]] = i; print();
			}
			else if (ans[0] != n - 1) {
				ans[++ans[0]] = i; sum += i;
			}
		}
		ans[0] = 0; sum = 0;
		FOR(i, 1, 30000) if (ans[0] < n && rand() % 5 < 5 && (i % 2 == 0 || i % 5 == 0 || i % 3 == 0)) {
			if (ans[0] == n - 1 && (sum + i) % 30 == 0) {
				ans[++ans[0]] = i; print();
			}
			else if (ans[0] != n - 1) {
				ans[++ans[0]] = i; sum += i;
			}
		}
		ans[0] = 0; sum = 0;
		FOR(i, 1, 30000) if (ans[0] < n && rand() % 5 < 4 && (i % 2 == 0 || i % 3 == 0 || i % 7 == 0 || i % 5 == 0)) {
			if (ans[0] == n - 1 && (sum + i) % 210 == 0) {
				ans[++ans[0]] = i; print();
			}
			else if (ans[0] != n - 1) {
				ans[++ans[0]] = i; sum += i;
			}
		}
		ans[0] = 0; sum = 0;
		FOR(i, 1, 30000) if (ans[0] < n && rand() % 5 < 4 && (i % 2 == 0 || i % 3 == 0 || i % 7 == 0 || i % 5 == 0 || i % 13 == 0)) {
			if (ans[0] == n - 1 && (sum + i) % 2730 == 0) {
				ans[++ans[0]] = i; print();
			}
			else if (ans[0] != n - 1) {
				ans[++ans[0]] = i; sum += i;
			}
		}
		ans[0] = 0; sum = 0;
		FOR(i, 1, 30000) if (ans[0] < n && rand() % 5 < 5 && (i % 2 == 0 || i % 7 == 0 || i % 5 == 0)) {
			if (ans[0] == n - 1 && (sum + i) % 70 == 0) {
				ans[++ans[0]] = i; print();
			}
			else if (ans[0] != n - 1) {
				ans[++ans[0]] = i; sum += i;
			}
		}
		ans[0] = 0; sum = 0;
		FOR(i, 1, 30000) if (ans[0] < n && rand() % 5 < 5 && (i % 2 == 0 || i % 7 == 0 || i % 3 == 0)) {
			if (ans[0] == n - 1 && (sum + i) % 42 == 0) {
				ans[++ans[0]] = i; print();
			}
			else if (ans[0] != n - 1) {
				ans[++ans[0]] = i; sum += i;
			}
		}
		ans[0] = 0; sum = 0;
		FOR(i, 1, 30000) if (ans[0] < n && rand() % 5 < 5 && (i % 2 == 0 || i % 3 == 0 || i % 5 == 0 || i % 13 == 0)) {
			if (ans[0] == n - 1 && (sum + i) % 390 == 0) {
				ans[++ans[0]] = i; print();
			}
			else if (ans[0] != n - 1) {
				ans[++ans[0]] = i; sum += i;
			}
		}
	}

	return 0;
}
