#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
	ll n; cin >> n; vector<ll> a(n), b(n);
	for(ll i = 0; i < n; i++)cin >> a[i];
	for(ll i = 0; i < n; i++)cin >> b[i];
	ll amari = 0;

	for(int i = 0; i < n; i++) amari += max(0LL, (b[i] - a[i]) / 2);
	for(int i = 0; i < n; i++) {
		if(a[i] <= b[i])continue;
		if(amari + b[i] >= a[i]) {
			amari -= (a[i] - b[i]);
		}else {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
};