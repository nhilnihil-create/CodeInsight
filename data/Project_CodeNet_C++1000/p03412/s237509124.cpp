#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

int N;
ll a[200000 + 10], b[200000 + 10];
vector<ll> amod[30], bmod[30];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)cin >> a[i];
	for (int i = 0; i < N; i++)cin >> b[i];

	for (int k = 1; k <= 30; k++) {
		amod[k - 1].resize(N), bmod[k - 1].resize(N);
		ll bit = (1LL << k);
		for (int i = 0; i < N; i++) {
			amod[k - 1][i] = a[i] % bit;
			bmod[k - 1][i] = b[i] % bit;
		}
	}

	ll ans = 0;

	for (int i = 0; i < 30; i++) {
		sort(bmod[i].begin(), bmod[i].end());
	}

	
	for (int k = 0; k <= 29; k++) {
		ll cnt1 = 0;
		for (int i = 0; i < N; i++) {
			//[2^k, 2 * 2^k)
			cnt1 += (lower_bound(bmod[k].begin(), bmod[k].end(), ((1LL << k) * 2) - amod[k][i]) - 
				lower_bound(bmod[k].begin(), bmod[k].end(), (1LL << k) - amod[k][i]));
			
			//[3 * 2^k, 4 * 2^k)

			cnt1 += (lower_bound(bmod[k].begin(), bmod[k].end(), ((1LL << k) * 4) - amod[k][i]) -
				lower_bound(bmod[k].begin(), bmod[k].end(), ((1LL << k) * 3) - amod[k][i]));
		}
		if (cnt1 & 1) {
			ans += (1LL << k);
		}
	}
	
	cout << ans << endl;

	return 0;
}