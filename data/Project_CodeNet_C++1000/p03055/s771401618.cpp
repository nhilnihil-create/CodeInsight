#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
const int INF=1e9,MOD=1e9+7,ohara=1e6+10;
const ll LINF=1e18;
using namespace std;
    
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define rrep(i,a,b) for(int i=(a);i<(b);i++)
#define rrrep(i,a,b) for(int i=(a);i>=(b);i--)
#define all(v) (v).begin(), (v).end()
#define Size(n) (n).size()
#define Cout(x) cout<<(x)<<endl
#define doublecout(a) cout<<fixed<<setprecision(15)<<a<<endl;
#define Cerr(x) cerr<<(x)<<endl
#define fi first
#define se second
#define P pair<ll,ll> 
#define m_p make_pair
#define V vector<ll> 
#define U_MAP unordered_map<ll,ll>
#define pq priority_queue<ll>
#define rpq priority_queue<ll,vector<ll>,greater<ll>>
#define p_b push_back
    
ll n,cnt,ans,a,b,c,d,tmp,tmpp,m,h,w,x,y,sum,pos,k;
ld doua;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
//int dy[]={-1,0,1,-1,1,-1,0,1};
//int dx[]={-1,-1,-1,0,0,1,1,1};
string alph("abcdefghijklmnopqrstuvwxyz"),s;
bool fl;
    
//-------------------------↓↓↓↓↓↓------------------------
    
//------ 自分を天才だと信じる ------

template< typename T >
struct edge {
  int src, to;
  T cost;
 
  edge(int to, T cost) : src(-1), to(to), cost(cost) {}
 
  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}
 
  edge &operator=(const int &x) {
    to = x;
    return *this;
  }
 
  operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;

template< typename T >
pair< T, int > dfs(const WeightedGraph< T > &g, int idx, int par) {
  pair< T, int > ret(0, idx);
  for(auto &e : g[idx]) {
    if(e.to == par) continue;
    auto cost = dfs(g, e.to, idx);
    cost.first += e.cost;
    ret = max(ret, cost);
  }
  return ret;
}
 
template< typename T >
T tree_diameter(const WeightedGraph< T > &g) {
  auto p = dfs(g, 0, -1);
  auto q = dfs(g, p.second, -1);
  return (q.first);
}
    
int main(void){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>n;
    WeightedGraph<ll> g(n);
    rep(i,n-1){
        cin>>a>>b;
        a--;b--;
        g[a].emplace_back(b,1LL);
        g[b].emplace_back(a,1LL);
    }
    ans=tree_diameter(g);
    if(ans%3==1)Cout("Second");
    else Cout("First");
    return 0;
}