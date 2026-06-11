#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define iter std::vector<int>::iterator

int main() {
	ios_base ::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<ll> vi (n);
	int odd = 0;
	for (int i=0; i<n; i++) {
		ll x;
		cin >> x;
		if (x < 0) {
			odd++;
		}
		vi[i] = abs(x);

	}

	sort(vi.begin(), vi.end());

	vi[0] = odd % 2 != 0 ? -vi[0] : vi[0];
	ll res = 0;
	for (ll x : vi) {
		res += x;
	}

	cout << res;

	return 0;	
}