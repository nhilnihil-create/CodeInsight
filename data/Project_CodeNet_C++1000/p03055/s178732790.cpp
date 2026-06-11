#include<bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ins insert
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define up_b upper_bound
#define low_b lower_bound
#define rep(i,a,b) for(ll i=a;i<=b;i++)
#define rev(i,a,b) for(int i=b;i>=a;i--)
#define boost ios_base::sync_with_stdio(NULL),cin.tie(NULL),cout.tie(NULL)
#define nl '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;

const int N=200001;
const int MXN=1000001;
const int inf=1e9;
const ll INF=1e18;

vi g[N];
int d[N];

void dfs(int v,int p){
  d[v]=d[p]+1;
  for(int i=0;i<sz(g[v]);i++){
    int to=g[v][i];
    if(to==p)continue;
    dfs(to,v);
  }
}

int main(){
  boost;
  int n;
  cin>>n;
  for(int i=1;i<n;i++){
    int u,v;
    cin>>u>>v;
    g[u].pb(v);
    g[v].pb(u);
  }
  dfs(1,1);
  int len=0,u=0;
  for(int i=1;i<=n;i++){
    if(len<d[i]){
      len=d[i];
      u=i;
    }
    d[i]=0;
  }
  dfs(u,u);
  int D=0;
  for(int i=1;i<=n;i++){
    D=max(D,d[i]);
  }
  D--;
  if(D%3==1)cout<<"Second";
  else cout<<"First";
  return 0;
}

