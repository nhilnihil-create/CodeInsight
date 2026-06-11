#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll calc(ll x) {
	return x*(x+1)/2;
}

int main() {
	int n;
	cin >> n;
	vector<ll> num(n+1);
	for (int i = 1; i <= n; i++) {
		ll a;
		cin >> a;
		num[i]=a;
	}
	int i = 1, j = 1;
	ll x = num[1];
	ll s = num[1];
	ll ans = 0;
	while (i <= n) {
		while (j < n && (num[j+1]^x)==(num[j+1]+s)) {
			j++;
			x^=num[j];
			s+=num[j];
		}
		ans+=calc(j-i+1);
		if (j == n) break;

		j++;
		x^=num[j];
		s+=num[j];

		while (x!=s) {
			x^=num[i];
			s-=num[i];
			i++;
		}

		if (i < j) {
			ans-=calc(j-1-i+1);
		}

	}
	cout << ans << "\n";
}
