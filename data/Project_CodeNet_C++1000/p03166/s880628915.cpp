
// Problem : G - Longest Path
// Contest : AtCoder - Educational DP Contest
// URL : https://atcoder.jp/contests/dp/tasks/dp_g
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
 
#define endl "\n"
#define int long long
#define FAST {ios_base::sync_with_stdio(false);cin.tie(NULL);}
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
#define rep(n) for(int i=0;i<(n);i++)
#define rrep(n) for(int i=(n)-1;i>=0;i--)
#define mem(a,b) memset((a),(b),sizeof (a))
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define INF (long long) 1e18
#define MOD 1000000007
const int MAX = 2e5+5;

int maxm = 0,n,m;
int dp[MAX],visited[MAX],deg[MAX];
vector<int> adj[MAX];
vector<int> adjT[MAX];

int32_t main(){
      cin>>n>>m;
      memset(dp,0,sizeof dp);
      memset(deg,0,sizeof deg);
      for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            adj[x].pb(y);
            adjT[y].pb(x);
            deg[y]++;
      }
      queue<int> que;
      for(int i=1;i<=n;i++){
            if(deg[i]==0) que.push(i);
      }
      while(!que.empty()){
            int node = que.front();
            que.pop();
            dp[node] = 0;
            for(int x : adjT[node]){
                  dp[node] = max(dp[node],1+dp[x]);
            }
            for(int parent : adj[node]){
                  deg[parent]--;
                  if(deg[parent]==0) que.push(parent);
            }
      }
      int maxm = 0;
      for(int i=1;i<=n;i++){
            maxm = max(maxm,dp[i]);
      }
      cout<<maxm<<endl;
      return 0;
}


