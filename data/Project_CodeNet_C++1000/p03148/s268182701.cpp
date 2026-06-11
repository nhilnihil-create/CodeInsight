#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("intt.txt", "r", stdin);
	freopen("outt.txt", "w", stdout);
#endif
	int n, k;
	cin >> n >> k;
	vector<pair<int, int> > v(n);
	long long ans = 0;
	for (int i = 0; i < n; i++)
		cin >> v[i].second >> v[i].first;
	sort(v.begin(), v.end(), greater<pair<int, int> > ());
	map<int, int> cnt;
	vector<pair<int, int> > taken;
	for (int i = 0; i < k; i++) {
		ans += v[i].first;
		cnt[v[i].second]++;
		taken.push_back({v[i].first, v[i].second});
	}
	int cursz = cnt.size();
	ans += 1LL * cursz * cursz;
	map<int, bool> vis;
	vector<int> arr;
	for (int i = k; i < n; i++) {
		if (cnt[v[i].second] == 0 && !vis[v[i].second]) {
			vis[v[i].second] = true;
			arr.push_back(v[i].first);
		}
	}
	int na = arr.size();
	int ptr = k - 1;
	long long mx = ans;
	for (int i = 0; i < na; i++) {
		while (ptr >= 0) {
			if (cnt[taken[ptr].second] > 1) {
				ans += arr[i];
				ans -= taken[ptr].first;
				ans -= 1LL * cursz * cursz;
				cursz++;
				ans += 1LL * cursz * cursz;
				mx = max(ans, mx);
				ptr--;
				break;
			}
			ptr--;
		}
	}
	cout << mx;
	return 0;
}
