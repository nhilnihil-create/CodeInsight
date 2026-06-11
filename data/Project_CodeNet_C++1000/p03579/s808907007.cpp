#include "bits/stdc++.h"

using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

//using Matrix = vector< vector<int> >;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1 << 30;
int dx[5] = {0, 0, 1, -1, 0}, dy[5] = {1, -1, 0, 0, 0};
bool cmp(P a, P b) { return a.second < b.second; } //End sort (Interval scheduling problem)

vector<int> G[100010];
int n, m;
int a[100010], b[100010];

int color[100010];

bool dfs(int v, int c) {
	color[v] = c;
	for (int i = 0; i < G[v].size(); i++) {
		if(color[G[v][i]] == c) return false;

		if(color[G[v][i]] == 0 && !dfs(G[v][i], -c)) return false;
	}

	return true;
}

int main(void){
	cin>>n>>m;
	for (int i = 0; i < m; i++)  {
		int a, b; cin>>a>>b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	for (int i = 0; i < n; i++) {
		if(color[i] == 0) {
			if(!dfs(i, 1)) {
				cout<< (ll)n * (n - 1) / 2 - m <<endl;
				return 0;
			}
		}
	}

	ll black = 0, white = 0;
	for (int i = 0; i < n; i++) {
		if(color[i] == 1) black++;
		else if(color[i] == -1) white++;
	}

	cout<< black * white - m <<endl;
	
	return 0;
}