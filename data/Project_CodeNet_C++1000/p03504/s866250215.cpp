
// D - Recording

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int rec[100001];
vector<pair<int, int>> plan[30];

int main() {
	int N, C;
	cin >> N >> C;

	int s, t, c;
	for (int i=0; i<N; i++) {
		cin >> s >> t >> c;
		c--;
		plan[c].push_back(make_pair(s, t));
	}

	for (int i=0; i<C; i++) {
		sort(plan[i].begin(), plan[i].end());

		int prev_t = -1;
		for (auto p : plan[i]) {
			int s = p.first;
			int t = p.second;
			if (s == prev_t) {
				rec[prev_t]++;
			} else {
				rec[s-1]++;
			}
			rec[t]--;
			prev_t = t;
		}
	}

	int ans = 0;
	for (int i=1; i<100001; i++) {
		rec[i] = rec[i-1] + rec[i];
		ans = max(ans, rec[i]);
	}

	cout << ans << endl;

	return 0;
}