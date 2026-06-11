#include <bits/stdc++.h>
using namespace std;

bool canAdd(vector<vector<int>>& edge) {
	using P = pair<int,int>;
	priority_queue<P, vector<P>, greater<P>> q;
	q.push(P(0, 0));
	vector<int> dp(edge.size(), 1e9+7), work(edge.size(), -1);

	while (q.size()) {
		auto p = q.top();
		q.pop();
		auto cost = p.first;
		auto now = p.second;

		if (dp[now] < cost) continue;
		dp[now] = cost;

		for (int i = 0; i < edge.size(); i++) {
			if (edge[now][i] && cost + 1 < dp[i]) {
				q.push(P(cost + edge[now][i], i));
				dp[i] = cost + edge[now][i];
				work[i] = now;
			}
		}
	}

	if (work[edge.size()-1] >= 0) {
		auto now = edge.size() - 1;
		while (now) {
			edge[now][work[now]] = true;
			edge[work[now]][now] = false;
			now = work[now];
		}

		return true;
	}

	return false;
}

int main() {
	int N;
	cin >> N;

	vector<int> a(N), b(N), c(N), d(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i] >> b[i];
		a[i]++;
		b[i]++;
	}
	for (int i = 0; i < N; i++) {
		cin >> c[i] >> d[i];
		c[i]++;
		d[i]++;
	}

	vector<vector<int>> edge(2*N+2,vector<int>(2*N+2));
	for (int i = 1; i <= N; i++) {
		edge[0][i] = true;
		edge[N+i][2*N+1] = true;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (a[i] < c[j] && b[i] < d[j]) {
				edge[i+1][N+j+1] = true;
			}
		}
	}

	int count = 0;
	auto used = vector<int>(edge.size());
	while (canAdd(edge)) {
		count++;
	}
	cout << count << endl;

	return 0;
}
