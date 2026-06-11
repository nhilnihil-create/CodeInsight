#include<bits/stdc++.h>
using namespace std;
#define R register int
#define AC 401000
#define LL long long

LL n;
int s[AC], d[AC], f[AC];

inline int read()
{
	int x = 0;char c = getchar();
	while(c > '9' || c < '0') c = getchar();
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x;
}

inline LL lowbit(int x){
	return x & (-x);
}

inline void add(int x){
	//printf("add : %d\n", x);
	for(R i = x; i <= 300000; i += lowbit(i)) d[i] += 1;
}

inline LL find(int x)
{
	LL rnt = 0;
	//printf("find : %d\n", x);
	for(R i = x; i; i -= lowbit(i)) rnt += d[i];
	return rnt;
}

void pre()
{
	n = read();
	for(R i = 1; i <= n; i ++) s[i] = read();
}

LL cal(int x)
{
	memset(f, 0, sizeof(f));
	memset(d, 0, sizeof(d));
	LL rnt = 0, k = 201000;//偏移量，防止负数
	for(R i = 1; i <= n; i ++) 
		f[i] = f[i - 1] + (s[i] <= x);
	for(R i = 1; i <= n; i ++)//枚举右端点
	{
		add(i - 2 * f[i - 1] + k);
		rnt += find(355000) - find(i - 2 * f[i] + 1 + k);
	}
	return rnt;
}

void half()
{
	int l = 0, r = 1000000000, mid;
	LL lim = (n * (n + 1) / 2) / 2 + 1;//这里乘的时候爆int了
	while(l < r)
	{
		mid = (l + r) >> 1;
		LL tmp = cal(mid);
		if(tmp >= lim) r = mid;
		else l = mid + 1;
	}	
	printf("%d\n", l);
}

int main()
{
	//freopen("in.in", "r", stdin);
	pre();
	half();
	//fclose(stdin);
	return 0;
}