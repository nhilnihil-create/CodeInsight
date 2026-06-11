
// Problem : B - Sum AND Subarrays
// Contest : AtCoder - Dwango Programming Contest V 
// URL : https://atcoder.jp/contests/dwacon5th-prelims/tasks/dwacon5th_prelims_b
// Memory Limit : 1024 MB
// Time Limit : 2525 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1001;

int n, k;
int a[N];
ll sum[N];
multiset<ll> ms;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	for (int l = 1; l <= n; l++) {
		for (int r = l; r <= n; r++) {
			ms.insert(sum[r] - sum[l - 1]);
		}
	}
	ll ans = 0;
	for (int i = 60; i >= 0; i--) {
		int cnt = 0;
		vector<ll> doom;
		for (auto& d : ms) {
			if ((d >> i) & 1) {
				cnt++;
			} else {
				doom.push_back(d);
			}
		}
		if (cnt >= k) {
			for (auto& x : doom) {
				ms.erase(ms.find(x));
			}
			ans |= 1ll << i;
		}
	}
	cout << ans;
}