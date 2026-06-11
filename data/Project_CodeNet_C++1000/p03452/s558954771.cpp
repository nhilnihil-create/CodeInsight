#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <numeric>
#include <regex>
#include <tuple>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
#define modulo 1000000007 // 10^9 + 7
#define INF 1000000000 // 10^9
#define LLINF 1LL<<60

int N, M;
vector<vector<P>> G(100001); // first  : 行先
								 // second : 距離
int Query[200001][3]; // [0] : L
					  // [1] : R
					  // [2] : D 

void input() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d", &Query[i][0], &Query[i][1], &Query[i][2]);
		G[Query[i][0]].push_back(P(Query[i][1], Query[i][2]));
		G[Query[i][1]].push_back(P(Query[i][0], -Query[i][2]));
	}

	// 確認
	/*
	for (int i = 1; i <= N; i++) {
		for (auto u : G[i]) {
			cout << i << "→" << u.first << "(" << u.second << ")   : ";
		}
		cout << endl;
	}
	*/
}

int pos[100001];
bool isfound[100001];

void dfs(int c, int d) { // c : 現在位置
						 // d : ここに至るまでの距離
	isfound[c] = true;
	pos[c] = d;

	for (P u : G[c]) {
		if (!isfound[u.first]) dfs(u.first, d + u.second);
	}
}

void solve() {
	for (int i = 1; i <= N; i++) isfound[i] = false;

	for (int i = 1; i <= N; i++) {
		if (!isfound[i]) dfs(i, 0);
	}

	// 確認
	bool flag = true;
	for (int i = 0; i < M && flag; i++) {
		if (pos[Query[i][1]] - pos[Query[i][0]] != Query[i][2]) {
			flag = false;

			// cout << i << "番目がダメでした" << endl;
		}
	}

	// for (int i = 1; i <= N; i++) cout << pos[i] << " ";

	if (flag) cout << "Yes" << endl;
	else cout << "No" << endl;
}


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	input();
	solve();

	return 0;
}