#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
typedef long long ll; 
typedef pair<int, int> P; 
const int mod = 1e9 + 7;
const int N = 2e6 + 5;
struct ed{
	int to, nxt;
}e[N << 1];
int head[N], tot = 1;
void add(int u, int v){
	e[tot].to = v, e[tot].nxt = head[u], head[u] = tot++;
}
ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a % b);
}
ll f[N], h[N], a[N], n, ans;
int  main()
{
	scanf("%lld", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &a[i]);
		if (i)
			f[i] = gcd(f[i - 1], a[i]);
		else
			f[i] = a[i];
	}
	for (int i = n - 1; i >= 0; i--)
	{
		if (i == n - 1)
			h[i] = a[i];
		else
			h[i] = gcd(h[i + 1], a[i]);
	}
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			ans = max(ans, h[i + 1]);
		else if (i == n - 1)
			ans = max(ans, f[n - 2]);
		else
			ans = max(ans, gcd(f[i - 1], h[i + 1]));
	}
	printf("%lld\n", ans);
}