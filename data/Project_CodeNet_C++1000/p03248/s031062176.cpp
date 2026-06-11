#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;

int main() {
	string s;
	cin >> s;
	int n = s.size();
	if (s[0] != '1' || s[n - 1] != '0') {
		cout << -1 << endl;
		return 0;
	}
	for (int i = 0; i < n - 1; i++) {
		if (s[i] != s[n - 2 - i]) {
			cout << -1 << endl;
			return 0;
		}
	}
	int m = 0;
	for (int i = n / 2 - 1; i >= 0; i--) {
		if (s[i] == '1') {
			m = i;
			break;
		}
	}
	vector<P> edge;
	queue<int> que;
	que.push(0);
	for (int i = 1; i <= m; i++) {
		if (s[i] == '0') {
			que.push(i);
		}
		else {
			while (!que.empty()) {
				edge.emplace_back(i, que.front());
				que.pop();
			}
			que.push(i);
		}
	}
	edge.emplace_back(m + 1, que.front());
	for (int i = m + 2; i < n; i++) {
		edge.emplace_back(m + 1, i);
	}
	for (int i = 0; i < n - 1; i++) {
		cout << edge[i].first + 1 << " " << edge[i].second + 1 << endl;
	}
}
