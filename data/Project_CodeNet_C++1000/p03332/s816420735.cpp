#include<iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <stack>
#include<bitset>
#include<list>
#include<cassert>
#include<numeric>

using namespace std;

const long long N = 3e5 + 5;
long long n, a, b, k;
long long ans = 0;
const long long mod = 998244353;
long long fac[N];

long long power(long long a, long long b)
{
	if (b == 0)
	{
		return 1ll;
	}
	long long ans = power(a, b / 2);
	ans = ans * ans;
	ans = ans % mod;
	if (b % 2 == 1)
	{
		ans = ans * a;
		ans = ans % mod;
	}
	return ans;
}

long long choose(long long a, long long b)
{
	long long ans = fac[a];
	ans = ans * power(fac[b], mod - 2);
	ans = ans % mod;
	ans = ans * power(fac[a - b], mod - 2);
	ans = ans % mod;
	return ans;
}

int main() 
{
	fac[0] = 1;
	for (long long i = 1; i < N; i++)
	{
		fac[i] = fac[i - 1] * i;
		fac[i] = fac[i] % mod;
	}
	cin >> n >> a >> b >> k;
	for (long long i = 0; i * a <= k && i <= n; i++)
	{
		if ((k - i * a) % b != 0)
			continue;
		long long red = (k - i * a) / b;
		if (red <= n)
		{
			ans += choose(n, i) * choose(n, red);
			ans = ans % mod;
		}
	}
	cout << ans << endl;
}
