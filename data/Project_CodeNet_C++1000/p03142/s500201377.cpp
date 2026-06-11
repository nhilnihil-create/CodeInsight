#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int N, M;
vector<vector<int>> E, ansE, revansE;
int cntin[100000 + 100], cntout[100000 + 100];
int d[100000 + 100], Log[100000 + 100];

int main() {
	cin >> N >> M;
	E.resize(N), ansE.resize(N);
	revansE.resize(N);
	for (int i = 0; i < N + M - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		E[a].push_back(b);
		cntout[a]++;
		cntin[b]++;
	}

	queue<int> q;
	for (int i = 0; i < N; i++) {
		if (cntin[i] == 0) {
			q.push(i);
			break;
		}
	}

	vector<int> sorted;
	while (q.size()) {
		int pos = q.front();
		q.pop();
		sorted.push_back(pos);
		
		for (int i = 0; i < E[pos].size(); i++) {
			int nxt = E[pos][i];
			cntin[nxt]--;
			if (cntin[nxt] == 0) {
				q.push(nxt);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < E[sorted[i]].size(); j++) {
			int nxt = E[sorted[i]][j];
			if (d[nxt] < d[sorted[i]] + 1) {
				d[nxt] = d[sorted[i]] + 1;
				Log[nxt] = sorted[i];
			}
		}
	}

	for (int i = 0; i < N; i++) {
		if (cntout[i] == 0) {
			//葉ならば
			int idx = i;
			while (idx != sorted[0]) {
				revansE[idx].push_back(Log[idx]);
				idx = Log[idx];
			}
		}
	}

	for (int i = 0; i < N; i++) {
		if (revansE[i].size() == 0)cout << 0 << endl;
		else cout << revansE[i][0] + 1 << endl;
	}
	return 0;
}