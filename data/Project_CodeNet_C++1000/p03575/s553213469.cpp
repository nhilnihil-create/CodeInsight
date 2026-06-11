#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>

#define DIV 1000000007
using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	int N, M; cin >> N >> M;
	vector<pair<int, int>> e(M);
	for (int i = 0; i < M; i++)
		cin >> e[i].first >> e[i].second;

	int ans = 0;
	for (int i = 0; i < M; i++) {
		vector<vector<int>> edges(N + 1);
		vector<bool> vi(N + 1);
		for (int j = 0; j < M; j++) {
			if (j == i) continue;
			int a = e[j].first, b = e[j].second;
			edges[a].push_back(b);
			edges[b].push_back(a);
		}
		stack<int> st;
		st.push(1);
		vi[1] = true;
		int cnt = 0;
		while (!st.empty()) {
			cnt++;
			int x = st.top();
			st.pop();
			for (auto to : edges[x]) {
				if (vi[to])continue;
				vi[to] = true;
				st.push(to);
			}
		}
		if (cnt != N) ans++;
		//cout << ans << endl;
	}
	cout << ans << endl;
}