#include<bits/stdc++.h>
#define ll long long
#define pb push_back 
using namespace std;

bool fun(const pair<int,int>& p1, const pair<int,int> & p2 ) { 
    return p1.second > p2.second ; 
}

const int MxN = 1e5+1; 
vector<int> adj[MxN] ; 
bool vis[MxN] ; 
int ct; 

void dfs(int u ) {
    ct++;
    vis[u] = true ; 
    for(int v : adj[u]) {
        if(!vis[v]) {
            vis[v] = true ; 
            dfs(v) ; 
        }
    }
}

void solve() {
    int n , m ; 
    cin >> n  >> m ; 
    vector<int> a(n , 0 )  ; 
    int x , y ,z; 
    for(int i = 0 ; i < m ; ++i) {
        cin >> x >> y >> z ; 
        adj[x].pb(y) ; 
        adj[y].pb(x) ; 
    }
/*    for(int  i = 1 ; i <= n ; ++i ){
        for(int j : adj[i]) 
            cout << j << " " ;
        cout << endl ;
    }*/
/*    vector<pair<int,int>> costs(n) ; 
    for(int  i = 1; i <= n ; ++i) {
        ct=0;
        memset(vis,false , sizeof(vis)) ; 
        dfs(i) ;
        //cout << i << " " << ct << endl ; 
        costs[i].first = i ;
        costs[i].second = ct ; 
    }*/

 
    int ans = 0 ;
    memset(vis,false , sizeof(vis)) ; 
    for(int i = 1 ; i <= n ; ++i) {
        //cout << costs[i].first << " ";
        if(!vis[i]) {
            dfs(i) ; 
            ans ++ ; 
        }
        
    }
    cout << ans  ; 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; 

	int t ; 
    //cin >> t ; 
    t =1 ; 
    while(t--)
        solve() ; 
    return 0;
}
