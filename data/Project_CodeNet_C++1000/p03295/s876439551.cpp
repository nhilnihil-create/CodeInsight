#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

bool cmp(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }

int main() {
	int N, M;
	cin >> N >> M;
	vector<pair<int, int>> v;
	for(int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({a, b});
	}

	sort(v.begin(), v.end(), cmp);

	int ans = 0, last = 0;
	for(int i = 0; i < M; i++) {
		if(last <= v[i].first) {
			last = v[i].second;
			ans++;
		}
	}
	cout << ans;
	return 0;
}
