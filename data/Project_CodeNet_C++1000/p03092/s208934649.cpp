#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();}
	return x * f;
}
const int N = 5100;
ll n,l,r,f[N],a[N];
int main()
{
	memset(f,0x3f,sizeof(f)); cin >> n >> r >> l;
	for(int i = 1;i <= n;i ++) a[i] = read() + 1;
	a[0] = 1; f[0] = 0; a[n + 1] = n + 2;
	for(int i = 1;i <= n + 1;i ++)
	{
		ll sr = 0,sl = 0;
		for(int j = i - 1;j >= 0;j --)
		{
			if(a[j] < a[i]) f[i] = min(f[i],f[j] + r * sr + l * sl);
			if(a[j] > a[i]) sr ++; else sl ++;
		}
	}
	cout << f[n + 1] << "\n";
	return 0;
}
