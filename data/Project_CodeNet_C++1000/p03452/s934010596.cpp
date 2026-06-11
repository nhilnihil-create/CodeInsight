#include <bits/stdc++.h>
#define MAXN 200100
#define pii pair<int, int>
#define pb push_back
typedef long long ll;

using namespace std;

int n, m, l[MAXN], r[MAXN], d[MAXN], p[MAXN];

vector<pii> g[MAXN];
bool vis[MAXN];

void dfs(int x, int pos){
	if(vis[x]) return;
	vis[x] = true;
	p[x] = pos;
	for(auto i : g[x]){
		dfs(i.first, i.second + pos);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
    	cin >> l[i] >> r[i] >> d[i];
    	l[i]--;
    	r[i]--;
    	g[l[i]].pb({r[i], d[i]});
    	g[r[i]].pb({l[i], -d[i]});
    }
    for(int i = 0; i < n; i++)
    	dfs(i, 0);
    for(int i = 0; i < m; i++){
    	if(p[r[i]] - p[l[i]] != d[i]){
    		cout << "No";
    		return 0;
    	}
    }
    cout << "Yes";
}