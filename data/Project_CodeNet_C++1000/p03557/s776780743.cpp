#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
// #include <bit>
// #include <bitset>
// #include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main()
{
	ll n;
	cin >> n;
	ll a[n];
	ll b[n];
	ll c[n];

	rep(i, n)
	{
		cin >> a[i];
	}
	rep(i, n)
	{
		cin >> b[i];
	}
	rep(i, n)
	{
		cin >> c[i];
	}
	sort(a, a + n);
	sort(b, b + n);
	sort(c, c + n);

	ll ans = 0;
	rep(i, n)
	{
		ll middle = b[i];
		ll a_index = lower_bound(a, a + n, middle) - a;
		ll b_index = upper_bound(c, c + n, middle) - c;

		ans += a_index * (n - b_index);
	}

	cout << ans << endl;
}

//g++ -std=c++17 -g main.cpp -o mai	n
