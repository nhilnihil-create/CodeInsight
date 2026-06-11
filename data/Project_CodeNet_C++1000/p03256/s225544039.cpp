//khodaya khodet komak kon
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()
#pragma GCC optimize ("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize ("-O2")


using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 200000 + 10;
const ll MOD = 1000000000 + 7;
const ll INF = 1000000010;
const ll LOG = 25;

int n, m, mark[N], cnt[N][2], num[N];
vector<int> V;
vector<int> G[N];

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		char c;
		cin >> c;
		num[i] = c - 'A';
	}
	for (int i = 0; i < m; i++){
		int v, u;
		cin >> v >> u;
		G[v].pb(u), G[u].pb(v);
		cnt[u][num[v]]++;
		cnt[v][num[u]]++;
	}
	for (int i = 1; i <= n; i++){
		if (cnt[i][0] == 0 || cnt[i][1] == 0) V.pb(i), mark[i] = 1;
	}
	while (V.size()){
		int fr = V.back();
		V.pop_back();
		for (auto u:G[fr]){
			cnt[u][num[fr]] --;
			if (cnt[u][num[fr]] == 0 && mark[u] == 0) mark[u] = 1, V.pb(u);
		}
	}
	for (int i = 1; i <= n; i++) if (!mark[i]) return cout << "Yes\n", 0;
	cout << "No";







	return 0;
}
