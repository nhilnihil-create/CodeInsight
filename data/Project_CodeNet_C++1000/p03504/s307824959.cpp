#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <queue>
#include <tuple>

using namespace std;
using PII = pair<int, int>;

int main() {
	int N, C;
	cin >> N >> C;

	int s, t, c;
	vector<vector<PII>> tvs(C+1);
	for (int i = 0; i < N; i++) {
		cin >> s >> t >> c;
		tvs[c].emplace_back(make_pair(s, t));
	}

	priority_queue<PII, vector<PII>, greater<PII>> que;
	for (auto tv: tvs) {
		if (tv.empty()) {
			continue;
		}
		sort(tv.begin(), tv.end());

		vector<PII> v;
		for (auto p: tv) {
			if (v.empty()) {
				v.emplace_back(p);
			} else if (p.first == v.back().second) {
				v.back().second = p.second;
			} else {
				v.emplace_back(p);
			}
		}

		for (auto p: v) {
			que.push(p);
		}
	}

	priority_queue<int, vector<int>, greater<int>> recorder;
	recorder.push(-1);

	while (!que.empty()) {
		tie(s, t) = que.top();
		que.pop();

		auto x = recorder.top();
		// printf("recorder %2d: s %d t %d\n", x, s, t);
		if (x < s) {
			recorder.pop();
			recorder.push(t);
		} else {
			// printf("add!\n");
			recorder.push(t);
		}
	}

	cout << recorder.size() << endl;
	return 0;
}
