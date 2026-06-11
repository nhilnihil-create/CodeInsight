#include "bits/stdc++.h"

using namespace std;

int main() {
	int N;
	cin >> N;
	map<int, int>mp;
	for (int i = 0; i < N; ++i) {
		int n;
		cin >> n;
		mp[n]++;
	}
	int ans = 0;
	for (auto p : mp) {
		if (p.first <= p.second) {
			ans += p.second - p.first;
		}
		else {
			ans += p.second;
		}
	}
	cout << ans << endl;
	return 0;
}
