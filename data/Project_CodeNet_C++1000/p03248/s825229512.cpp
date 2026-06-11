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

char s[maxn];
int cnt = 1;

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

void build(int x, int idx)
{
	if(idx == 0) return;
	while(s[idx] == '0')
	{
		printf("%d %d\n", x, ++cnt);
		idx--;
	}
	printf("%d %d\n", x, ++cnt);
	build(cnt, idx-1);
}

int main(void)
{
	s[0] = '0';
	scanf("%s", s+1);
	int n = strlen(s) - 1;
	if(s[1] != '1' || s[n-1] != '1')
	{
		printf("-1");
		return 0;
	}
	rep1(i, 0, n/2)
	{
		if(s[i] != s[n-i])
		{
			printf("-1");
			return 0;
		}
	}
	build(1, n-1);
	
	return 0;
} 