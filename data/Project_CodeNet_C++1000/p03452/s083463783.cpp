#include <bits/stdc++.h>

#define debug(x) cout << #x << " = " << x << endl
#define fori(i, ini, lim) for(int i = int(ini); i < int(lim); i++)
#define ford(i, ini, lim) for(int i = int(ini); i >= int(lim); i--)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> data;

enum {UNVISITED, VISITED, EXPLORED};

const int MAX = 2e5 + 5;
vector<ii> adj[MAX];
int state[MAX];
int degree[MAX];
int pos[MAX];
int n, m;

void die() {
	puts("No");
	exit(0);
}

void dfs(int node) {
	state[node] = VISITED;
	for(auto &each : adj[node]) {
		if(state[each.first] == UNVISITED) {
			pos[each.first] = pos[node] + each.second; 
			dfs(each.first);
		}
	}
	state[node] = EXPLORED;
}

int main() {
	scanf("%d %d", &n, &m);

	vector<data> v;
	fori(i, 1, m + 1) {
		int l, r, d;
		scanf("%d %d %d", &l, &r, &d);
		adj[l].emplace_back(r, d);
		degree[r]++;
	}

	fori(i, 1, n + 1) {
		if(degree[i] == 0) {
			dfs(i);
		}
	}

/*	fori(i, 1, n + 1) {
		cout << "pos[" << i << "] = " << pos[i] << endl;
	}
*/
	fori(i, 1, n + 1) {
		for(auto &each : adj[i]) {
			int other, dis;
			tie(other, dis) = each;

			if(pos[other] - pos[i] != dis) {
				die();
			}
		}
	}

	puts("Yes");

	return 0;
}
