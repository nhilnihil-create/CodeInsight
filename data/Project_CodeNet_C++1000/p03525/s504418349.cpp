#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n;
	cin>>n;

	ll d[60];
	ll ans = INT_MAX;
	for(ll i=0;i<n;i++) cin>>d[i];

	sort(d, d+n);
	ans = d[0];

	ll dd[60];
	ll maxmin = -1;

	ll temp = INT_MAX;
	for(ll i=1;i<n;i++) temp = min(temp, d[i] - d[i-1]);
	maxmin = max(maxmin, temp);

	for(ll j=0;j<n;j+=2) {
		for(ll i=0;i<n;i++) dd[i] = d[i];
		for(ll i=0;i<=j;i+=2) dd[i] = 24 - dd[i];
		sort(dd, dd+n);

		ll temp = INT_MAX;
		for(ll i=1;i<n;i++) temp = min(temp, dd[i] - dd[i-1]);
		maxmin = max(maxmin, temp);
	}

	cout<<min(maxmin, ans)<<endl;
	
}