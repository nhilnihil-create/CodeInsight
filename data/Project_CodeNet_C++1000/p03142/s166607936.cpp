#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define pb push_back
#define mp make_pair
#define Would
#define you
#define please

vector<int> E[100001], IE[100001];
int num = 1;
int topo[100001], visit[100001];
void dfs(int v) {
	if (visit[v]) return;
	for (int to : E[v]) {
		dfs(to);
	}
	visit[v] = 1;
	topo[v] = num++;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int N, M;
	cin >> N >> M;
	bool kodomo[100001] = {};
	rep(i, N + M - 1) {
		int a, b;
		cin >> a >> b;
		E[a].pb(b);
		IE[b].pb(a);
		kodomo[b] = 1;
	}

	int rt = 0;
	rep1(i, N) if (!kodomo[i]) {
		rt = i;
		break;
	}

	dfs(rt);
	rep1(i, N) {
		int kotae = 0;
		int saishou = 1e9;
		if (rt == i) kotae = 0;
		else {
			for (int u : IE[i]) {
				if (saishou > topo[u]) {
					saishou = topo[u];
					kotae = u;
				}
			}
		}
		co(kotae);
	}

	Would you please return 0;
}