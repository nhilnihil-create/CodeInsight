#include<bits/stdc++.h>
using namespace std;

#define deb(x) cerr<<"["#x<<" : "<<x<<" ]\n";

int main()
{
	using ll = long long;
	int n, m;
	cin >> n >> m;
	ll ans = 0, sum = 0;
	unordered_map<ll, ll> mp;
	
	mp[sum] = 1;
	for(int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		sum = (sum + x) % m;
		ans += mp[sum];
		mp[sum]++;
	}
	cout << ans;
}
