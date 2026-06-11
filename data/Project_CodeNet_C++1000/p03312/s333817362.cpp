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

ll T[maxn], S[maxn];

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
	int n = read();
//	int n = 1e5;
	rep1(i, 1, n)
	{
		T[i] = read();
//		T[i] = i;
		S[i] = S[i-1] + T[i];
	}
	ll ans = INF;
	rep1(i, 2, n-2)
	{
		ll A, B, C, D;
		A = C = 0;
		B = S[i];
		D = S[n] - S[i];
		int l, r;
		l = 1;
		r = i;
		while(l <= r)
		{
			int mid = (l + r) >> 1;
			if(S[mid] * 2 < B) l = mid + 1;
			else r = mid - 1;
		}
		if(abs(S[l-1]*2-B) < abs(S[r+1]*2-B))
		{
			A = S[l-1];
			B = B - A;
		}
		else
		{
			A = S[r+1];
			B = B - A;
		}
		l = i+1; 
		r = n;
		while(l <= r)
		{
			int mid = (l + r) >> 1;
			if((S[mid]-S[i]) * 2 < D) l = mid + 1;
			else r = mid - 1;
		}
		if(abs((S[l-1]-S[i])*2-D) < abs((S[r+1]-S[i])*2-D))
		{
			C = S[l-1] - S[i];
			D = D - C;
		}
		else
		{
			C = S[r+1] - S[i];
			D = D - C;
		}
		ans = min(ans, max(max(A, B), max(C, D)) - min(min(A, B), min(C, D)));
	}
	cout<<ans;
	
	return 0;
} 