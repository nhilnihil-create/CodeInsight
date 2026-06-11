#include <bits/stdc++.h>
using namespace std;
 
#define MOD (998244353)
#define f first
#define s second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(x) x.begin(), x.end()
#define print(vec,l,r) for(int i = l; i <= r; i++) cout << vec[i] <<" "; cout << endl;
#define forf(i,a,b) for(int i = (a); i < (b); i++)
#define forr(i,a,b) for(int i = (a); i > (b); i--)
#define input(vec,N) for(int i = 0; i < (N); i++) cin >> vec[i];
typedef long long int ll;
#define ld long double
const int N = 2e5+30;

vector < vector < int > > adj(N);
vector < int > vis(N,0);
int n,m;

vector<int> ans;

void dfs(int v) {
    vis[v] = true;
    for (int u : adj[v]) {
        if (!vis[u])
            dfs(u);
    }
    //cout<<v<<'\n';
    ans.push_back(v);
}

void topological_sort() {
    vis.assign(N, false);
    ans.clear();
    for (int i = 1; i <= n; ++i) {
        if (!vis[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
}

void solve(){
   //int n,m;
   cin>>n>>m;
   for(int i=1;i<=m;i++){
     int u,v;
     cin>>u>>v;
     adj[u].pb(v);
   }
   int dp[n+3];
   memset(dp,0,sizeof(dp));
   topological_sort();
   vis.assign(N, false);
   for(auto x : ans){
     //cout<<x<<"\n";
     if(!vis[x]){
       int s = x;
       queue < int > q;
       q.push(s);
       vis[s] = true;
       while(q.size()){
         int v = q.front();
         q.pop();
         for(auto u : adj[v]){
           dp[u] = max(dp[u],dp[v]+1);
           //cout<<u<<" "<<v<<" "<<dp[u]<<'\n';
         }
       }
     }
   }
   cout<<*max_element(dp+1, dp+n+1)<<'\n';
}

 
int main(){
 	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	int T;
  //cin >> T;
  //cout<<prs.size()<<'\n';
	T = 1;
  //visited[1]=1;
	while(T--){
		solve();
	}
}