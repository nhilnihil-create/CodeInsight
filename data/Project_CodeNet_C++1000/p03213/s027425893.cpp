#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll ans = 0;
vector<ll> v;

void f(ll i, ll j, ll k) {
	if (i == j && j == k) {
		if (v[i] >= 74)++ans;
	}
	else if (i == j) {
		if (v[i] >= 14 && v[k] >= 4)++ans;
	}
	else if (i == k) {
		if (v[i] >= 14 && v[j] >= 4)++ans;
	}
	else if(j==k) {
		if (v[i] >= 2 && v[j] >= 24)++ans;
	}
	else {
		if (v[i] >= 2 && v[j] >= 4 && v[k] >= 4)++ans;
	}
}

int main() {
	ll n;
	cin >> n;
	map<ll, ll> prime;
	for (ll i = 2; i <= n; ++i) {
		ll a = i;
		for (ll j = 2; j <= a; ++j) {
			while (a % j == 0) {
				++prime[j];
				a /= j;
			}
		}
	}
	for (auto p : prime)v.push_back(p.second);
	for (ll i = 0; i < v.size(); ++i) {
		for (ll j = 0; j < v.size(); ++j) {
			for (ll k = j; k < v.size(); ++k) {
				f(i, j, k);
			}
		}
	}
	cout << ans << endl;
}