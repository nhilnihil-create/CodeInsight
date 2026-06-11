#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL)


int main() {
	fastIO;
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (auto& i : v) {
		cin >> i;
	}
	int mx = 0;
	for (int i = -1; i < n; i++) {
		for (int j = i+1; j < n+1; j++) {
			int items = i+1 + n-j;
			if (items > k)
				continue;
			vector<int> taken;
			for (int l = 0; l <= i; l++) {
				taken.push_back(v[l]);
			}
			for (int r = n-1; r >= j; r--) {
				taken.push_back(v[r]);
			}
			sort(taken.begin(), taken.end());
			for (int l = 0; l < min(k-items, (int)taken.size()); l++) {
				if (taken[l] < 0)
					taken[l] = 0;
			}
			int sum = 0;
			for (auto item : taken) {
				sum += item;
			}
			mx = max(mx, sum);
		}
	}
	cout << mx;

}
