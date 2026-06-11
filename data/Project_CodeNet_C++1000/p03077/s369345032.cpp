#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	ll N;
	cin >> N;

	vector <ll> nin(5);
	for (int ii = 0; ii < 5; ++ii){
		cin >> nin[ii];
	}
	sort(nin.begin(), nin.end());

	ll div = nin[0];
	ll ans = (N + div - 1 ) / div + 4;

	cout << ans << "\n";

	return 0;
}
