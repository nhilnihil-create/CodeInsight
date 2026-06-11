#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
inline int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch < '0' || ch > '9')	{if(ch == '-')	f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();}
	return x * f;
}
const int N = 1e3 + 5;
int n;
int X[N] , Y[N] , len[N];
char s[50];
int main()
{
	n = read(); int tmp = -1;
	for(int i = 1;i <= n;i ++)
	{
		X[i] = read(); Y[i] = read();
		if(tmp == -1) tmp = abs(X[i] + Y[i]) & 1;
		else if((abs(X[i] + Y[i]) & 1) != tmp) return puts("-1") , 0;
	}
	printf("%d\n1",32 - tmp);
	len[1] = 1; int cnt = 1;
	if(tmp) for(int i = 1;i <= 30;i ++) printf(" %d",len[++ cnt] = 1 << i);
	else for(int i = 0;i <= 30;i ++) printf(" %d",len[++ cnt] = 1 << i);
	puts("");
	for(int i = 1;i <= n;i ++)
	{
		ll x = 0 , y = 0 , dx , dy;
		for(int j = cnt;j >= 1;j --)
		{
			dx = X[i] - x; dy = Y[i] - y;
			if(abs(dx) > abs(dy)) 
			{
				if(dx > 0) x += len[j] , s[j] = 'R';
				else x -= len[j] , s[j] = 'L';
			}
			else
			{
				if(dy > 0) y += len[j] , s[j] = 'U';
				else y -= len[j] , s[j] = 'D';
			}
		}
		printf("%s\n",s + 1);
	}
	return 0;
}