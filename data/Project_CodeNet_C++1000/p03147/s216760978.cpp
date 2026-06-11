// In the name of God

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;

	vector<int> a(n);

	for(int i = 0; i < n; i++) cin >> a[i];

	int ans = 0;
	
	priority_queue<pair<int,int>> pq;

	for(int i = 0; i < n; i++) pq.push(make_pair(-a[i], i));

	while(!pq.empty()) {
		int now = pq.top().second;
		pq.pop();
		ans += a[now];
		for(int j = now + 1; j < n; j++) {
			if(a[j] == 0) break;
			a[j] -= a[now];
		}
		for(int j = now - 1; j >= 0; j--) {
			if(a[j] == 0) break;
			a[j] -= a[now];
		}
		a[now] = 0;
	}

	cout << ans;

	return 0;
}
