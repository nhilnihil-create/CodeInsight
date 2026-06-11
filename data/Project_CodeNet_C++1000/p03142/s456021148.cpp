#include<bits/stdc++.h>

using namespace std;
#define taskname "A"
#define pb	push_back
typedef long double ld;
typedef long long ll;
const int maxn = 2e5 + 5;
int n ,m , deg[maxn];
vector<int> adj[maxn];
int res[maxn];

void dfs(int u ,int v){
    vector<int> tmp;
    for(int c : adj[u])if(--deg[c] == 0)tmp.pb(c);
    for(int c : tmp){
        if(deg[c] ==  0){
            res[c] = u;
            dfs(c,u);
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if(fopen(taskname".INP","r")){
        freopen(taskname".INP", "r",stdin) ,
        freopen(taskname".OUT", "w",stdout);
	}
    cin >> n >> m;
    for(int i = 1 ; i <= m + n - 1  ; ++i){
        int u,v;cin >> u >> v;adj[u].pb(v);
        deg[v]++;
    }
    for(int i =1  ; i <= n ; ++i)if(deg[i]==0){
        dfs(i,0);
        break;
    }
    for(int i =1;i<=n;++i)cout<<res[i]<<"\n";
}
