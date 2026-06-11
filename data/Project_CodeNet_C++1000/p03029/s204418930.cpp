#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll a, p;
	scanf("%lld %lld", &a, &p);
	p += a * 3;
	a = p / 2;
	printf("%lld\n", a);
	return 0;
}