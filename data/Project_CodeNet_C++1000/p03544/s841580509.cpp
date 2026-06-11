#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;

int main()
{
	ll a = 2LL, b = 1LL;
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		swap(a,b);
		b += a;
	}
	cout << b << endl;
}
