#include <bits/stdc++.h>

#define For(i, j, k) for (int i = j; i <= k; ++ i)
#define Forr(i, j, k) for (int i = j; i >= k; -- i)

using namespace std;

inline void File() {
	freopen("D.in", "r", stdin);
	freopen("D.out", "w", stdout);
}

int L, cnt, h, t;
struct edge { int u, v, w; } E[100];

inline void add(int x, int y, int z) {
	E[++ cnt].u = x, E[cnt].v = y, E[cnt].w = z;
}

int main() {

	cin >> L;
	for (int tt = L; tt; ++ h, tt >>= 1);

	For(i, 1, h - 1) {
		add(i, i + 1, 1 << h - i - 1);
		add(i, i + 1, 0);
	}

	t = 1 << h - 1;
	Forr(i, h - 1, 1) if (L >> (i - 1) & 1) add(1, h - i + 1, t), t += 1 << i - 1;

	cout << h << ' ' << cnt << endl;
	For(i, 1, cnt) printf("%d %d %d\n", E[i].u, E[i].v, E[i].w);

	return 0;
}
