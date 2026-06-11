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
	ll v[n];
	for(ll i = b; i >= 1; i--){
		v[n-t] = i;
		t--;
	}

	ll excd = 0;
	for(ll i = 2 * b; i <= a * b; i += b){
		ll d = min(t - (a - i / b), b);
		excd += b - d;
		v[n-t] = i - excd;
		t--;
		
		for(ll j = 0; j < d - 1; j++){
			v[n-t] = i - j - 1 - excd;
			t--;
		}

	}

	rep(i, n){
		cout << v[i] << (i == n - 1 ? "\n" : " ");
	}

}
