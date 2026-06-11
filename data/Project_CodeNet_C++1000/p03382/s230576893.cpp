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

const int MAXN = 100010;

int n;
int A[MAXN];

int abs(int x) {return x < 0 ? -x : x;}

int main()
{
	in(n);
	FOR(i, 1, n) in(A[i]);

	std::sort(A + 1, A + n + 1);

	int min = 0x3f3f3f3f, son;
	
	FOR(i, 1, n - 1) {
		if (abs(A[i] - A[n] / 2) <= min) min = abs(A[i] - A[n] / 2), son = A[i];
	}

	printf("%d %d\n", A[n], son);
	
	return 0;
}
