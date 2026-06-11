#include<cstdio>
#include<algorithm>
#include<vector>
#include<bitset>
using namespace std;
char p[8010];
bitset<16384>T;
int x, y, C[8010], ex, ey;
bool OK(int st, int d, int ed) {
	int t = abs(ed - st);
	if (t % 2 == d % 2 && t <= d)return true;
	return false;
}
bool Pos(int ck, int d) {
	if (abs(d) > 8000)return false;
	int i;
	T.reset();
	T[8192] = 1;
	for (i = ck; i <= 8000; i+=2) {
		if (C[i]) {
			T = (T >> C[i]) | (T << C[i]);
		}
	}
	if (T[8192 + d])return true;
	return false;
}
int main() {
	int i, c = 0;
	scanf("%s", p);
	for (i = 0; p[i]; i++) {
		if (p[i] == 'T')c++;
		else {
			if (c == 0)x++;
			else C[c]++;
		}
	}
	scanf("%d%d", &ex, &ey);
	if (Pos(0, ex - x) && Pos(1, ey))puts("Yes");
	else puts("No");
}