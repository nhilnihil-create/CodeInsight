#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

const long INF = 1L << 60;

bool f[110][10];
int p[110][11];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> f[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 11; j++) {
			cin >> p[i][j];
		}
	}

	vector<int> adj[10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < n; j++) {
			if (f[j][i]) adj[i].push_back(j);
		}
	}

	long ans = -INF;
	for (int i = 0; i < (1 << 10); i++) {
		long sum = 0;
		vector<int> cnt(n, 0);
		for (int j = 0; j < 10; j++) {
			if (i & (1 << j)) {
				for (auto s : adj[j])
					cnt[s]++;
			}
		}
		bool flag = true;
		for (int j = 0; j < n; j++) {
			sum += p[j][cnt[j]];
			if (cnt[j]) flag = false;
		}
		if (flag) continue;
		ans = max(ans, sum);
	}
	cout << ans << endl;
}