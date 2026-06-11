#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
#include<cstring>
#include<unordered_map>
#include<unordered_set>
#include<tuple>
#include<vector>

using namespace std;

const int MAXN = 200000 + 10;
const int MAXM = 200000 + 10;

int cnt[MAXN][2];
int Step[MAXN];
int Q[MAXN];
int s[MAXN];
int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;

	string buf;
	cin >> buf;
	memset(Step, 0, sizeof(Step));
	for (int i = 0; i < n; i++) {
		// cout << cnt[i][0] << cnt[i][1] << endl;
		s[i + 1] = (buf[i] == 'B');
	}
	vector<vector<int>> g(n + 1);
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		cnt[x][s[y]]++;
		cnt[y][s[x]]++;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	int Tail = 0;
	for (int i = 1; i <= n; i++) {
		if (cnt[i][0] == 0 || cnt[i][1] == 0) {
			Q[Tail] = i;
			Step[i] = 1;
			Tail++;
		}
	}

	for (int Head = 0; Head < Tail; Head++) {
		int cur = Q[Head];
		for (int k : g[cur]) {
			cnt[k][s[cur]]--;
			if (cnt[k][s[cur]] == 0 && (!Step[k])) {
				Step[k] = 1;
				Q[Tail++] = k;
			}
		}
	}
	// cout << Tail << endl;
	cout << ((Tail == n) ? "No" : "Yes") << endl;
	return 0;
}
