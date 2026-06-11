#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

vector<int> G[200002];
ii cnt[200002];
bitset<200002> ins;

int main() {
	int N, M;
	string s;
	cin >> N >> M >> s;
	auto cmp = [](int a, int b) {
		if ((cnt[a].first == 0 || cnt[a].second == 0) && (cnt[b].first == 0 || cnt[b].second == 0)) return a < b;
		if (cnt[a].first == 0 || cnt[a].second == 0) return true;
		if (cnt[b].first == 0 || cnt[b].second == 0) return false;
		else return a < b;
	};
	set<int, decltype(cmp)> S(cmp);
	for (int i = 0; i < N; ++i) {
		cnt[i] = ii(0, 0);
		S.insert(i);
	}
	while (M--) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		if (a == b) {
			G[a].push_back(a);
			S.erase(a);
			s[a] == 'A' ? ++cnt[a].first : ++cnt[a].second;
			S.insert(a);
		}
		else {
			G[a].push_back(b);
			G[b].push_back(a);
			S.erase(a);
			S.erase(b);
			s[a] == 'A' ? ++cnt[b].first : ++cnt[b].second;
			s[b] == 'A' ? ++cnt[a].first : ++cnt[a].second;
			S.insert(a);
			S.insert(b);
		}
	}
	ins.set();
	while (!S.empty() && (cnt[*S.begin()].first == 0 || cnt[*S.begin()].second == 0)) {
		int u = *S.begin();
		S.erase(u);
		ins[u] = 0;
		for (auto& v : G[u]) {
			if (ins[v]) {
				S.erase(v);
				s[u] == 'A' ? --cnt[v].first : --cnt[v].second;
				S.insert(v);
			}
		}
	}
	
	cout << (S.empty() ? "No" : "Yes") << '\n';
}