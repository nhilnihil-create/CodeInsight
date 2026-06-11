#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define foreach(it, S) for(__typeof (S.begin()) it = S.begin(); it != S.end(); it++)
#define all(x) x.begin(), x.end()
#define endl '\n'
#define _ ios_base :: sync_with_stdio (false); cin.tie (NULL);

const double eps = 1e-9;
const int MAXN = int (5e6) + 256, MXN = int (1e6);
const int MOD = int (1e9) + 7;

inline int nxtnt() {
	int s = 1, x = 0, c = getc(stdin);
	while (c <= 32)
		c = getc(stdin);
	if (c == '-')
		s = -1, c = getc(stdin);
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getc(stdin);
	return x * s;
}

template <typename T> inline T gcd (T a, T b) { while (a && b) a > b ? a %= b : b %= a; return a + b; }
inline bool Palindrome (const string& s) { return equal (s.begin(), s.end(), s.rbegin()); }

int a[MAXN];

inline int diff(int a, int b) {
	return abs(a-b);
}

int main () { // _
	int n = nxtnt();

	for (int i = 0; i < n; ++i) {
		a[i] = nxtnt();
	}

	int N = max_element(a, a + n) - a;
	int K = 0;

	if (N == K) ++K;

	for (int i = 0; i < n; ++i) if (i != N) {
		if (diff(a[K], a[N] / 2) > diff(a[i], a[N] / 2))
			K = i;
	}

	printf("%d %d\n", a[N], a[K]);

	return 0;
}
