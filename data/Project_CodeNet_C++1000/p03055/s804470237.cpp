#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<functional>
#include<iomanip>

using namespace std;

typedef long long ll;

int N;
vector<vector<int>> E;

void dfs(int pos, int bef, vector<int>& dis) {
	for (int i = 0; i < E[pos].size(); i++) {
		int nxt = E[pos][i];
		if (nxt == bef)continue;
		dis[nxt] = dis[pos] + 1;
		dfs(nxt, pos, dis);
	}
}

int get_diameter() {
	vector<int> dis(N);
	dfs(0, -1, dis);
	int longest = 0, idx = -1;
	for (int i = 0; i < N; i++) {
		if (longest < dis[i]) {
			longest = dis[i], idx = i;
		}
	}

	dis.clear();
	dis.resize(N);
	dfs(idx, -1, dis);

	int res = -1;
	for (int i = 0; i < N; i++) {
		if (res < dis[i])res = dis[i];
	}
	return res;
}

int main() {

	cin >> N;
	E.resize(N);

	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		E[a].push_back(b), E[b].push_back(a);
	}

	int dm = get_diameter();

	if (dm % 3 == 1) {
		cout << "Second" << endl;
	}
	else 
		cout << "First" << endl;

	return 0;
}
