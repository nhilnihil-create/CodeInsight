#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
#include<set>
#include<map>
using namespace std;
typedef long long LL;
const int N = 1010;
#define int long long
inline int read()
{
	register int x = 0 , f = 0; register char c = getchar();
	while(c < '0' || c > '9') f |= c == '-' , c = getchar();
	while(c >= '0' && c <= '9') x = (x << 3) + (x << 1) + c - '0' , c = getchar();
	return f ? -x : x;
}
int n;
int x[N] , y[N] , len[50];
inline int Abs(int x) { return x < 0 ? -x : x; }
signed main()
{
	n = read();
	for(int i = 1 ; i <= n ; ++i) x[i] = read() , y[i] = read();
	int tmp = Abs(x[1] + y[1]) & 1;
	for(int i = 2 ; i <= n ; ++i) if((Abs(x[i] + y[i]) & 1) != tmp) { puts("-1"); return 0; }
	cout << (32 - tmp) << '\n'; // (0 , 0)是偶数;
	int tot = 0; len[tot = 1] = 1; cout << 1 << ' ';
	if(tmp)
		for(int i = 1 ; i <= 30 ; ++i) len[++tot] = 1 << i , cout << len[tot] << ' ';
	else
		for(int i = 0 ; i <= 30 ; ++i) len[++tot] = 1 << i , cout << len[tot] << ' ';
	cout << '\n';
	char ans[32];
	for(int i = 1 ; i <= n ; ++i)
	{
		int nowx = 0 , nowy = 0;
		for(int j = tot ; j >= 1 ; --j)
		{
			int dx = Abs(nowx - x[i]) , dy = Abs(nowy - y[i]);
			if(dx > dy)
			{
				if(nowx < x[i]) nowx += len[j] , ans[j] = 'R'; else nowx -= len[j] , ans[j] = 'L';
			}
			else
			{
				if(nowy < y[i]) nowy += len[j] , ans[j] = 'U'; else nowy -= len[j] , ans[j] = 'D';
			}
		}
		for(int j = 1 ; j <= tot ; ++j) putchar(ans[j]); cout << '\n';
	}
	return 0;
}