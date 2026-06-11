#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, x;
	cin >> N >> x;
	vector<int> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		if (x >= a[i]) {
			if (i == N - 1 && x != a[i]) {
				break;
			}
			x -= a[i];
			++cnt;
		} else {
			break;
		}
	}
	cout << cnt << '\n';
	
	return 0;
}
