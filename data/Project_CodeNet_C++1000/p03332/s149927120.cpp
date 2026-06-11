#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e5+10;
const int mod = 998244353;

int n,a,b,k;
int g[N],rev[N];

long long binpow(int a,int x)
{
 
	long long res;
	if(x == 0) return 1;
	res = binpow(a,x/2) % mod;
	if(x % 2 == 0) return res*res % mod;
	else return ((a*res) % mod * res) % mod;
}

void add(long long &x, long long y) { x = (x + y) % mod; }

long long tohop(int k,int n)
{
	if(k < 0 || n < 0 || k > n) return 0;
	int val = g[n-k]*g[k] % mod;
	return (g[n] * binpow(val,mod-2)) % mod;
}

signed main()
{
	int ans = 0;
	cin>>n>>a>>b>>k;
	g[0] = 1;
	for(int i=1;i<N;i++)
	{
		g[i] = ((g[i-1] % mod) * (i % mod)) % mod;
	}

	for(int i=0;i<=n;i++)
	{
		if((k - a*i) % b == 0)
		{
			int j = (k-a*i)/b;
			int val = tohop(i,n) * tohop(j,n) % mod;
				add(ans, val);
		}
	}

	cout<<ans;
}