#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int maxn = 3e5 + 10;
ll fac[maxn], inv[maxn], facinv[maxn], bin[maxn];
void pre()
{
	fac[0] = 1; for(int i = 1; i < maxn; ++i) fac[i] = fac[i - 1] * i % mod;
	inv[1] = 1; for(int i = 2; i < maxn; ++i) inv[i] = (mod - mod / i) * inv[mod % i] % mod;
	facinv[0] = 1; for(int i = 1; i < maxn; ++i) facinv[i] = facinv[i - 1] * inv[i] % mod;
	bin[0] = 1; for(int i = 1; i < maxn; ++i) bin[i] = bin[i - 1] * 2 % mod;
}
ll C(int n, int m) { return n < m ? 0 : fac[n] * facinv[m] % mod * facinv[n - m] % mod;}
ll n, a, b, k, ans;
int main()
{
	pre();
	cin >> n >> a >> b >> k;
	for(int x = 0; x <= min(n, k / a); ++x)
		if((k - a * x) % b == 0)
		{
			int y = (k - a * x) / b;
			if(y <= n)
			{
				ans = (ans + C(n, x) * C(n, y) % mod) % mod;
			}
		}
	cout << ans << endl;
	return 0;
}