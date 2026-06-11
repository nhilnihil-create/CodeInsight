#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#define inf 0x3f3f3f3f3f3f3f3fll
using namespace std;
typedef long long ll;

template <typename Tp> inline void getint(Tp &num){
	register int ch, neg = 0;
	while(!isdigit(ch = getchar())) if(ch == '-') neg = 1;
	num = ch & 15;
	while(isdigit(ch = getchar())) num = num * 10 + (ch & 15);
	if(neg) num = -num;
}

int N, m, X[1005], Y[1005], mx = 0, isodd = -1, d[35];
char dirs[35], dir;

signed main(){
	getint(N);
	for(register int i = 1; i <= N; i++){
		getint(X[i]), getint(Y[i]), mx = max(mx, abs(X[i]) + abs(Y[i]));
		if(isodd == -1) isodd = (X[i] ^ Y[i]) & 1;
		else if(isodd != ((X[i] ^ Y[i]) & 1)) return puts("-1"), 0;
	}
	for(m = d[1] = 1; (1LL << m) <= mx; m++) d[m + 1] = 1 << m;
	if(!isodd) d[++m] = 1;
	sort(d + 1, d + m + 1), dirs[m] = '\0', printf("%d\n", m);
	for(register int i = 1; i <= m; i++) printf("%d ", d[i]); puts("");
	for(register int k = 1; k <= N; k++){
		register ll x = 0, y = 0;
		for(register int i = m; i; i--){
			register ll mn = inf, cur, nx, ny;
			if((cur = llabs(x + d[i] - X[k]) + llabs(y - Y[k])) < mn) mn = cur, dir = 'R', nx = x + d[i], ny = y;
			if((cur = llabs(x - d[i] - X[k]) + llabs(y - Y[k])) < mn) mn = cur, dir = 'L', nx = x - d[i], ny = y;
			if((cur = llabs(x - X[k]) + llabs(y + d[i] - Y[k])) < mn) mn = cur, dir = 'U', nx = x, ny = y + d[i];
			if((cur = llabs(x - X[k]) + llabs(y - d[i] - Y[k])) < mn) mn = cur, dir = 'D', nx = x, ny = y - d[i];
			dirs[i - 1] = dir, x = nx, y = ny;
		}
		puts(dirs);
	}
	return 0;
}