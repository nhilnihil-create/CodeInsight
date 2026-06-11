#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

signed main(void)
{
	ll a, b, ans;	
	cin >> a >> b;

	if (b % 2 == 0)
		b = (b / 2 % 2) ^ b;
	else
		b = (b + 1) / 2 % 2;
	a--;
	if (a % 2 == 0)
		a = (a / 2 % 2) ^ a;
	else
		a = (a + 1) / 2 % 2;
	ans = b ^ a;
	cout << ans << endl;
	return 0;
}
