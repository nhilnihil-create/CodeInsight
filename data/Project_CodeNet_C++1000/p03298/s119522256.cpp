#include <iostream>
#include <cstdio>
using namespace std;
int n;
char ch[40];
int l[20], qr;
long long f[20][20][20], ans;
bool inq[20][20][20];
pair <int, pair <int, int> > q[8010];
inline void dfs (int step, int l1, int l2) {
	if (step > n) {
		f[0][l1][l2] = 1;
		qr = 0, q[++qr] = make_pair (0, make_pair (l1, l2));
		for (int i = 1; i <= qr; i++) {
			int p = q[i].first, lx = q[i].second.first, ly = q[i].second.second; ++p;
			if (p > n) ans += f[p - 1][lx][ly];
			else {
				if (ch[p + n] == ch[lx]) {
					f[p][l[lx]][ly] += f[p - 1][lx][ly];
					if (!inq[p][l[lx]][ly])
						q[++qr] = make_pair (p, make_pair (l[lx], ly));
					inq[p][l[lx]][ly] = true;
				}
				if (ch[p + n] == ch[ly]) {
					f[p][lx][l[ly]] += f[p - 1][lx][ly];
					if (!inq[p][lx][l[ly]])
						q[++qr] = make_pair (p, make_pair (lx, l[ly]));
					inq[p][lx][l[ly]] = true;
				}
			}
			f[p - 1][lx][ly] = inq[p - 1][lx][ly] = 0;
		}
		return;
	}
	l[step] = l1;
	dfs (step + 1, step, l2);
	l[step] = l2;
	dfs (step + 1, l1, step);
}
int main () {
	scanf ("%d", &n);
	scanf ("%s", ch + 1);
	dfs (2, 1, 0);
	printf ("%lld\n", ans << 1);
	return 0;
}