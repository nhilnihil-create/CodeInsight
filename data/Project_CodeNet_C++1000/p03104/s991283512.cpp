#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll findXOR(ll n)
{
	ll mod = n % 4;

	if (mod == 0)
		return n;

	else if (mod == 1)
		return 1;

	else if (mod == 2)
		return n + 1;

	else if (mod == 3)
		return 0;
}

ll findXOR(ll l, ll r)
{
	return (findXOR(l - 1) ^ findXOR(r));
}
int main()
{
	ll x,y;
	cin>>x>>y;

	cout << findXOR(x, y);

	return 0;
}
