#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 200100;
typedef __int128 ll;
const ll oo = ((ll)1 << 100);
void out(ll x)
{
	if(x > 9)
		out(x / 10);
	cout << (int)(x % 10);
}
void in(ll &x)
{
	string s;
	cin >> s;
	x = 0;
	for(int i = 0; i < s.size(); i ++)
		x = x * 10 + s[i] - '0';
}
ll x[maxn] = {0}, h[maxn] = {0};
ll m;
int n;
ll ans = oo;
void work(int k)
{
	ll sum = (n + k) * m + (h[n] - h[n - k]) * 2;
	//cout << sum << endl;
	ll j = 0;
	int i;
	for(i = n - k + 1; i >= 1; i -= k)
	{
		j ++;
		sum += (h[i + k - 1] - h[i - 1]) * (j + j + 1);
		//cout << i << " " << i + k - 1 << " " << j << " " << sum << endl;
		//cout << h[i + k - 1] << " " << h[i - 1] << endl;
	}
	j ++;
	i += k - 1;
	sum += h[i] * (j + j + 1);
	ans = min(ans, sum);
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n;
	in(m);
	for(int i = 1; i <= n; i ++)
	{
		//cin >> x[i];
		in(x[i]);
		h[i] = h[i - 1] + x[i];
	}
	//work(1);
	
	for(int k = 1; k <= n; k ++)
		work(k);
	out(ans);
	cout << endl;	
	return 0;
}