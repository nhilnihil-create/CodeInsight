
// D - Islands War

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	int N, M;
	cin >> N >> M;

	vector<pair<int, int>> requests;

	for (int i=0; i<M; i++) {
		int l, r;
		cin >> l >> r;
		requests.push_back(make_pair(r, l));
	}

	sort(requests.begin(), requests.end());

	int ans = 0;
	int max_r = 0;
	for (pair<int, int> req : requests) {
		int l = req.second;
		int r = req.first;
		if (r > max_r && l >= max_r) {
			ans++;
			max_r = r;
		}
	}

	cout << ans << endl;

	return 0;
}