#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll n, a, b;
	cin >> n >> a >> b;

	if(a + b - 1 > n || a * b < n){
		cout << -1 << endl;
		return 0;
	}

	ll t = n;
	vector<ll> v;
	for(ll i = b; i >= 1; i--){
		v.push_back(i);
		t--;
	}

	for(ll i = 2 * b; i <= a * b; i += b){
		v.push_back(i);
		t--;
		ll d = t - (a - i / b);
		for(ll j = 0; j < min(d, b - 1); j++){
			v.push_back(i - j - 1);
			t--;
		}
	}

	vector<ll> w(n);
	rep(i, n) w[i] = v[i];
	sort(w.begin(), w.end());

	rep(i, n){
		cout << lower_bound(w.begin(), w.end(), v[i]) - w.begin() + 1 << (i == n - 1 ? "\n" : " ");
	}

}
