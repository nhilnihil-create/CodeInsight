#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <ctime> 
using namespace std;

#define pb push_back
#define All(a) a.begin(), a.end()
#define met(a, b) memset(a, b, sizeof(a))
#define rep1(i, l, r) for(int i = l; i <= r; ++i)
#define rep2(i, l, r) for(int i = l; i < r; ++i) 
#define per(i, r, l) for(int i = r; i >= l; --i)
typedef long long ll;
typedef double db;
typedef long double ldb;
const int NIL = -1;
const int oo = 0x3f3f3f3f;
const ll INF = 2e18;
const db eps = 1e-8;
const db PI = acos(-1.0);
const int maxn = 1e5 + 7;

struct node
{
	int u, v, w;
}G[100];

inline int read(void)
{
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9')	{ if(ch == '-') f = -1; ch = getchar(); } 
	while(ch >= '0' && ch <= '9') {	x = (x << 1) + (x << 3) + ch - '0';	ch = getchar();	}
	return x * f;
}

inline void write(int x)
{
	if(x < 0) { putchar('-'); x = -x; }
    if(x >= 10) write(x/10); 
	putchar(x%10+'0'); 
}

int main(void)
{
	int L = read();
	L--;
	int sum = 0, x = 1;
	int n = 1, m = 0;
	while(sum + x <= L)
	{
		sum += x;
		G[m].u = n;
		G[m].v = n+1;
		G[m++].w = 0;
		G[m].u = n;
		G[m].v = n+1;
		G[m++].w = x;
		n++;
		x *= 2;
	}
	while(sum < L)
	{
		sum++;
		int val = sum;
		x = 1;
		int idx = 1;
		while(sum + x <= L)
		{
			sum += x;
			idx++;
			x *= 2;
		}
		G[m].u = idx;
		G[m].v = n;
		G[m++].w = val;
	}
	printf("%d %d\n", n, m);
	rep2(i, 0, m)
	{
		printf("%d %d %d\n", G[i].u, G[i].v, G[i].w);
	}
	
	
	return 0;
} 