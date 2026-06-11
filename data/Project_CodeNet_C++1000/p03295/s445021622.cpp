#include "bits/stdc++.h"
using namespace std;

bool comp(const pair<int, int> a, const pair<int, int> b) {
	return a.second < b.second;
}

int main() {
	int N, M;
	cin >> N >> M;
	vector<pair<int, int>>P(M);
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		P[i] = make_pair(a, b);
	}
	sort(P.begin(), P.end(), comp);
	int ans = 0;
	pair<int, int> p;
	for (int i = 0; i < M; ++i) {
		if (0 == ans) {
			ans++;
			p = P[i];
		}
		else {
			if (p.second <= P[i].first) {
				ans++;
				p = P[i];
			}
		}
	}
	cout << ans << endl;
}
