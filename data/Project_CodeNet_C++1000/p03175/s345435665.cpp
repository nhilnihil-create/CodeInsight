#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define lb lower_bound
#define ub upper_bound
#define srt(a) sort(a.begin(),a.end())
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pair<int,int>> vpii;
#define mxe(a) *max_element(a.begin(),a.end())
#define mne(a) *min_element(a.begin(),a.end())
#define endl '\n'
#define mod 1000000007
#define INF64 1e18
const int N=100005;
vi g[N];
vi black(N,1),white(N,1);
vector<bool> visited(N,0);
void dfs(int u){
  visited[u]=1;
  for(int v:g[u]){
    if(visited[v]==0){
      dfs(v);
      black[u]*=white[v];
      black[u]%=mod;
      white[u]*=(white[v]+black[v]);
      white[u]%=mod;
    }
  }
}
void solve(){
  int n ;cin>>n;
  for(int i=1;i<n;i++){
    int x,y;cin>>x>>y;
    g[x].pb(y);
    g[y].pb(x);
  }
  dfs(1);
  cout<<(white[1]+black[1])%mod;
}

int32_t main(){
  #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
  #endif
  
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int T=1;
  //cin>>T;
  for(int TT=1;TT<=T;TT++){
    solve();
  }
}