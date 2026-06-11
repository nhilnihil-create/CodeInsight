#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <fstream>
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
const int maxn = 2e5 + 7;

int T[maxn], c[maxn], a[maxn];

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

int lowbit(int x)
{
	return x&(-x);
}

void upd(int idx, int val)
{
	for(int i = idx; i < maxn; i += lowbit(i))
	{
		c[i] += val;
	}
}

ll qry(int idx)
{
	ll ans = 0;
	for(int i = idx; i > 0; i -= lowbit(i))
	{
		ans += c[i];
	}
	return ans;
}

bool check(ll n)
{
	met(c, 0);
	ll sum = 0;
	rep1(i, 0, n)
	{
		sum += qry(T[i]);
		upd(T[i], 1);
	}
	return sum >= (n * (n - 1) / 2 + n - 1) / 2 + 1;
}

int main(void)
{
	int n = read();
	int l = 1, r = 0;
	rep1(i, 1, n)
	{
		a[i] = read();
		r = max(r, a[i]);
	}
	T[0] = 1e5 + 1;
//	if(n == 1)
//	{
//		printf("%d", a[1]);
//		return 0;
//	}
	while(l <= r)
	{
		int mid = (l + r) >> 1;
		rep1(i, 1, n)
		{
			T[i] = T[i-1] + (a[i]>=mid?1:-1);
		} 
		if(check(n)) l = mid + 1;
		else r = mid - 1;
	}
	printf("%d", l-1);
	
	return 0;
} 