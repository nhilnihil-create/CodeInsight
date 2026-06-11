#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int read()
{
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = 0; c = getchar(); }
	while(isdigit(c)) { x = (x << 3) + (x << 1) + (c ^ 48); c = getchar(); }
	return f ? x : -x;
}

typedef long long LL;
const int maxn = 1e5 + 10, mod = 1e9 + 7;
int inv[maxn], a[maxn];

int main()
{

	int n = read();
	inv[0] = inv[1] = 1;
	for(int i = 2; i <= n; ++i) inv[i] = (LL)(mod - mod / i) * inv[mod % i] % mod;
	for(int i = 1; i <= n; ++i) a[i] = read();
	for(int i = 2; i <= n; ++i) (inv[i] += inv[i - 1]) %= mod;
	int ans = 0;
	for(int i = 1; i <= n; ++i) (ans += (LL)a[i] * (inv[i] - 1 + inv[n - i + 1]) % mod) %= mod;
	for(int i = 1; i <= n; ++i) ans = (LL)ans * i % mod;
	cout << ans << endl;
	
	return 0;
}