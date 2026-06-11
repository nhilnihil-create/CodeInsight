#include <iostream>
#include <cstring>
#include<vector>
#include <algorithm>
#include<cstdlib>
#include<set>
#include<math.h>
#include<map>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(ll i=0;i<n;i++)


int main()
{
	ll n, m;
	cin >> n >> m;
	ll ans = 0;
	ll a, b;
	vector<ll> x(m);
	vector<ll> y(m);
	
	for (ll i = 0; i < m; i++)
	{
		cin >> x[i] >> y[i];
	}
	int min = *min_element(y.begin(), y.end());
	int max = *max_element(x.begin(), x.end());
	if (max <= min)
	{
			ans = min - max + 1;
	}
	
	cout << ans << "\n";
	return 0;
}