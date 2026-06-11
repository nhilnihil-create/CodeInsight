#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int H, W, N;
int x, y;
char s[MAXN], t[MAXN];

void load() {
	scanf("%d%d%d%d%d", &H, &W, &N, &x, &y);
	scanf("%s%s", s, t);
}

bool in_range(int val, int lo, int hi) {
	return val >= lo && val <= hi;
}

void up(int &ref, int val) {
	if (ref < val)
		ref = val;
}

void down(int &ref, int val) {
	if (ref > val)
		ref = val;
}

bool solve() {
	int lox = 1, hix = H;
	int loy = 1, hiy = W;
	for (int i = N - 1; i >= 0; i--) {
		if (t[i] == 'L')
			hiy++;
		else if (t[i] == 'R')
			loy--;
		else if (t[i] == 'U')
			hix++;
		else
			lox--;
		up(lox, 1);
		up(loy, 1);
		down(hix, H);
		down(hiy, W);
		if (s[i] == 'L')
			loy++;
		else if (s[i] == 'R')
			hiy--;
		else if (s[i] == 'U')
			lox++;
		else
			hix--;
		up(lox, 1);
		up(loy, 1);
		down(hix, H);
		down(hiy, W);
		if (lox > hix || loy > hiy)
			return false;
	}
	return in_range(x, lox, hix) && in_range(y, loy, hiy);
}

int main() {
	load();
	puts(solve() ? "YES" : "NO");
	return 0;
}