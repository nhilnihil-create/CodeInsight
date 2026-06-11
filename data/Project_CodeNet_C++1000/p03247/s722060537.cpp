#include <bits/stdc++.h>

#define For(i, j, k) for (int i = j; i <= k; ++ i)
#define Forr(i, j, k) for (int i = j; i >= k; -- i)

using namespace std;

inline int read() {
	int x = 0, p = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') p = -1;
	for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
	return x * p;
}

inline void File() {
	freopen("D.in", "r", stdin);
	freopen("D.out", "w", stdout);
}

const int N = 1e3 + 10;
int X[N], Y[N], n;

inline void fuck(int x, int y) {
	Forr(i, 30, 0) {
		int d = 1 << i;
		if(abs(x) > abs(y)) 
			putchar(x < 0 ? (x += d, 'L') : (x -= d, 'R'));
		else 
			putchar(y < 0 ? (y += d, 'D') : (y -= d, 'U'));
	}
}

int main() {

	n = read();
	For(i, 1, n) X[i] = read(), Y[i] = read();

	int flag = X[1] + Y[1] & 1;

	For(i, 2, n) if ((X[i] + Y[i] & 1) != flag) return puts("-1"), 0;

	For(i, 1, n) Y[i] += (!flag); printf("%d\n", 32 - flag);

	Forr(i, 30, 0) printf("%d ", 1 << i); puts(!flag ? "1" : "");

	For(i, 1, n) fuck(X[i], Y[i]), puts(!flag ? "D" : "");

	return 0;
}
