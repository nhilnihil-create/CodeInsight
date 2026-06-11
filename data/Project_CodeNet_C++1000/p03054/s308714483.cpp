#include <bits/stdc++.h>

#define LL long long
#define pa pair<int,int>
using namespace std;
const int inf = 2147483647;
const int N = 200001;

int _max(int x, int y) {return x > y ? x : y;}
int _min(int x, int y) {return x < y ? x : y;}
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x * f;
}
void put(int x) {
	if(x < 0) putchar('-'), x = -x;
	if(x >= 10) put(x / 10);
	putchar(x % 10 + '0');
}

char s1[N], s2[N];

int main() {
	int H = read(), W = read(), n = read();
	int sx = read(), sy = read();
	scanf("%s%s", s2 + 1, s1 + 1);
	int xl = 1, xr = H, yl = 1, yr = W;
	for(int i = n; i >= 1; i--) {
		if(s1[i] == 'U') xr = _min(xr + 1, H);
		else if(s1[i] == 'D') xl = _max(xl - 1, 1);
		else if(s1[i] == 'L') yr = _min(yr + 1, W);
		else yl = _max(yl - 1, 1);
		if(s2[i] == 'U') xl++;
		else if(s2[i] == 'D') xr--;
		else if(s2[i] == 'L') yl++;
		else yr--;
		if(xl > xr || yl > yr) {puts("NO"); return 0;}
	} if(xl <= sx && sx <= xr && yl <= sy && sy <= yr) puts("YES");
	else puts("NO");
	return 0;
}

