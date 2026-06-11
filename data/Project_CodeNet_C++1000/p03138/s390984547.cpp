#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxx = 1e5 + 7;
int n;
ll k;
ll a[maxx];
ll ans, sum;

void Init() {
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
}

void Solve() {
	for(int bit = 60; bit >= 0; bit--) {
		ll dd = 1ll << bit;
		int cnt1 = 0, cnt0 = 0;
		for(int i = 1; i <= n; i++) {
			if(a[i] & dd) cnt1++;
			else cnt0++;
		}
		if(cnt0 >= cnt1) {
			if(ans + dd <= k) ans += dd;
			else ans += 0ll << bit;
		}
		else ans += 0ll << bit;
	}
	for(int i = 1; i <= n; i++) sum += ans ^ a[i];
	cout << sum << endl;
}

int main() {
	Init();
	Solve();
	return 0;
}