#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, B = y; i <= B; i ++)
#define ff(i, x, y) for(int i = x, B = y; i <  B; i ++)
#define fd(i, x, y) for(int i = x, B = y; i >= B; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 2e5 + 5;

int n, a[N];

struct P {
	int x, y;
	P(int _x = 0, int _y = 0) {
		x = _x, y = _y;
	}
};
P b[N]; int b0;

int pd(int m) {
	b[b0 = 1] = P(1, a[1]);
	fo(i, 2, n) {
		if(a[i] > a[i - 1]) {
			b[++ b0] = P(1, a[i] - a[i - 1]);
		} else {
			int s = a[i - 1] - a[i];
			while(s > 0) {
				if(b[b0].y > s) {
					b[b0].y -= s;
					s = 0;
				} else {
					s -= b[b0 --].y;
				}
			}
			if(b[b0].x < m) {
				if(b[b0].y > 1) {
					b[b0].y --;
					int x = b[b0].x;
					b[++ b0] = P(x + 1, 1);
				} else b[b0].x ++;
			} else {
				if(b0 == 1) return 0;
				if(b[b0 - 1].y > 1) {
					b[b0 + 1] = b[b0];
					b[b0] = P(b[b0 - 1].x + 1, 1);
					b[b0 - 1].y --;
					b0 ++;
					b[b0].x = 1;
				} else {
					b[b0 - 1].x ++;
					b[b0].x = 1;
					int t = b0 --;
					while(b0 > 1 && b[b0 - 1].x == b[b0].x) {
						b[b0 - 1].y += b[b0].y;
						b0 --;
					}
					b[++ b0] = b[t];
				}
			}
		}
		while(b0 > 1 && b[b0 - 1].x == b[b0].x) {
			b[b0 - 1].y += b[b0].y;
			b0 --;
		}
	}
	return 1;
}

int main() {
	scanf("%d", &n);
	fo(i, 1, n) scanf("%d", &a[i]);
	int as = 0;
	for(int l = 1, r = n; l <= r; ) {
		int m = l + r >> 1;
		if(pd(m)) as = m, r = m - 1; else l = m + 1;
	}
	pp("%d\n", as);
}
