/*
by.YXH_XianYu
   2018.8.25
 */
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LLI long long
#define DBL double
#define CHR char
#define BOL bool
#define REG register
#define rep(i, j, k) for(int i = j, lim = k; i <= lim; i++)
#define req(i, j, k) for(int i = j, lim = k; i >= lim; i--)
#define MXN 100005

int n,
	a[MXN],
	s[MXN];

#define Lowbit(x) ((x)&(-(x)))
int bit[MXN << 1], bitLim = 200000;
void Modify(int x) {
	for(; x <= bitLim; x += Lowbit(x)) bit[x] ++;
}
LLI Query(int x) {
	LLI res = 0; for(; x; x -= Lowbit(x)) res += bit[x]; return res;
}
void Init() {
	for(REG int i = 1; i <= bitLim; i ++) bit[i] = 0;
}

bool Judge(int x) {
	REG int i;
	Init();
	s[0] = 0;
	for(i = 1; i <= n; i ++)
		s[i] = s[i-1] + (a[i]>=x?1:-1);
	LLI sum = 0;
	for(i = 0; i <= n; i ++) {
		sum += Query(s[i] + MXN);
		Modify(s[i] + MXN);
	}
	return sum >= 1ll*n*(n+1)/4;
}

int main() {
	//freopen("TEMPLATE.in", "r", stdin);
	//freopen("TEMPLATE.out", "w", stdout);
	REG int i, l, r, md;

	scanf("%d", &n);
	l = 1; r = 0;
	for(i = 1; i <= n; i ++)
		scanf("%d", &a[i]), r = std::max(r, a[i]);
	while(l <= r) {
		md = (l + r) >> 1;
		if(Judge(md))
			l = md + 1;
		else
			r = md - 1;
	}
	printf("%d\n", r);
	return 0;
}
