#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

int main() {
	int n, k, a;
	cin >> n >> k;
	map<int, int> kind;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (kind.count(a)) {
			kind[a]++;
		} else {
			kind.emplace(a, 1);
		}
	}
	vector<int> cnt;
	for (auto x : kind)
		cnt.push_back(x.second);
	sort(cnt.begin(), cnt.end());
	int ans = 0;
	for (int i = 0; i < (int) cnt.size() - k; i++)
		ans += cnt[i];
	cout << ans << endl;
}