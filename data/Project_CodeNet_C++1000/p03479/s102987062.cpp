#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef long long ll;
typedef long double ld;

int  main()
{
	ll x,y; cin >> x >> y;
	vector<ll> a;
	int p = 0;
	while (x * (ll)pow(2 , p) <= y)
	{
		a.push_back(x * (ll)pow(2,p));
		p++;
	}
	cout << a.size() << endl;
	return 0;
}