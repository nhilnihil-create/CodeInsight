#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

int main() {
	int N, M;
	cin >> N >> M;
	vector<pair<int, int>> v(M);
	for(int i = 0; i < M; i++) cin >> v[i].second >> v[i].first;
	sort(v.begin(), v.end());

	int ans = 1, cut = v[0].first;
	for(int i = 1; i < M; i++) {
		if(cut <= v[i].second) {
			ans++;
			cut = v[i].first;
		}
	}
	cout << ans << "\n";
	return 0;
}