#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0; i<int(n); i++)
#define FOR(i,m,n) for(int i=int(m); i<int(n); i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define VI vector<int>
#define VLL vector<long long>
#define VVI vector<vector<int>>
#define VVLL vector<vector<long long>>
#define VC vector<char>
#define VS vector<string>
#define VVC vector<vector<char>>
#define fore(i,a) for(auto &i:a)

typedef pair <int, int> P;
template<class T> bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }
const int  INF = 1 << 30;
const ll INFL = 1LL<<60;
const ll mod =1000000009;

const int max_V = 100005;
vector<int> G[max_V];
vector<int> color(max_V);
int n;

bool dfs(int v, int c) {
	color[v] = c;
	for (int i : G[v]) {
		if (color[i] == c)return false;
		if (color[i] == 0 && !dfs(i, -c))return false;
	}
	return true;
}

bool is_bipartite() {
	REP(i, n) {
		if (color[i] == 0) {
			if (!dfs(i, 1))return false;
		}
	}
	return true;
}

int main() {
	

	int m;
	cin >> n >> m;

	REP(i, m) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	if (is_bipartite()) {
		ll a = count(ALL(color), 1);
		ll b = count(ALL(color), -1);

		cout << a * b - m << endl;
	}
	else {
		ll v = n;
		cout << v * (v - 1) / 2 - m << endl;
	}


}