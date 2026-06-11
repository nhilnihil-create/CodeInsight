#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main() {

	int n; cin >> n;
	vector<pair<int, int>> p, q;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		p.push_back({ a,b });
	}
	for (int i = 0; i < n; i++) {
		int c, d; cin >> c >> d;
		q.push_back({ c,d });
	}
	sort(p.begin(), p.end());
	sort(q.begin(), q.end());
	int ans = 0;
	int index = 0;
	int cntInBox = 0;
	vector<bool> used(n, false);
	for (int i = 0; i < n; i++) {
		int line = q[i].first;
		while (true) {
			if (index == n) break;
			if (q[i].first < p[index].first) {
				break;
			}
			index++;
			cntInBox++;
		}
		if (cntInBox == 0) continue;
		int ansIndex;
		int tmp = -1;
		for (int j = 0; j < index; j++) {
			if (used[j]) continue;
			if (p[j].second < q[i].second) {
				if (chmax(tmp , p[j].second)) {
					ansIndex = j;
				}
			}
		}
		if (tmp != -1) {
			ans++;
			used[ansIndex] = true;
			cntInBox--;
		}
	}
	cout << ans << endl;
	return 0;
}