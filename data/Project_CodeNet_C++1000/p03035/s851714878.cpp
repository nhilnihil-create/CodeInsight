#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
  	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll a, b;
	scanf("%lld %lld", &a, &b);
	if(a < 6)
	{
		b = 0;
	}
	else if(a >= 6 && a <= 12)
	{
		b /= 2;
	}
	printf("%lld\n", b);
	return 0;
}