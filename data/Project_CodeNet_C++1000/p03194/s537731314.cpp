#include <bits/stdc++.h>

using namespace std;

#define Rep(i,a,b)  for (int i=(a);i<(b);i++)
#define rep(i,n)    for (int i=0;i<(n);i++)
#define all(x)      (x).begin(), (x).end()

#define ll long long

int main()
{
	ll n, p;
	map<ll, ll> mp;
	cin >> n >> p;
	if (n == 1) {
		cout << p << endl;
		return 0;
	}
	int ans = 1;
	for (int i = 1; pow(i, n) <= p; i++) {
		if (p % (ll)pow(i, n) == 0)
			ans = i;
	}
	cout << ans << endl;
}

