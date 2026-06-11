// In the name of God

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	priority_queue<int> pq;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		pq.push(-x);
	}
	vector<pair<int,int>> v;
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back(make_pair(y, x));
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	for(int i = 0; i < m; i++) {
		int x = v[i].second, y = v[i].first;
		while(-pq.top() < y && x) {
			x--;
			pq.pop();
			pq.push(-y);
		}
	}

	long long s = 0;
	while(pq.size()) {
		s += -pq.top();
		pq.pop();
	}

	cout << s;

	
		
	return 0;
}
