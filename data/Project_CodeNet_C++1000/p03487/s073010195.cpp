#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

void solve() {
	int n;
	cin >> n;
	map<int, int> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		m[x]++;
	}
	int ans = 0;
	for (auto i : m) {
		if (i.first > i.second) ans += i.second;
		if (i.first < i.second) ans += i.second - i.first;
	}
	cout << ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
	int T = 1; 
    //cin >> T;
    while(T--) solve();
}