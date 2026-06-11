#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main() {
	int N, M; cin >> N >> M;
	vector<int>x(N, 0); stack<int>s;
	vector<vector<pair<int, int>>>L(N), R(N);
	for (int i = 0, lef, rig, d; i < M; i++) {
		cin >> lef >> rig >> d; lef--; rig--;
		L[rig].push_back({ lef,d }); R[lef].push_back({ rig,d });
	}
	for (int i = 0; i < N; i++) {
		if (L[i].size() == 0) {
			x[i] = 1; s.push(i);
		}
	}

	bool ok = true;
	while (!s.empty()) {
		int node = s.top(); s.pop();
		for (int i = 0; i < R[node].size(); i++) {
			int next = R[node][i].first, xd = x[node] + R[node][i].second;
			if (x[next] == 0) {
				x[next] = xd;
				s.push(next);
			}
			else if (x[next] != xd) {
				ok = false; break;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		if (x[i] == 0)ok = false;
	}
	cout << (ok ? "Yes" : "No") << endl;

	return 0;
}