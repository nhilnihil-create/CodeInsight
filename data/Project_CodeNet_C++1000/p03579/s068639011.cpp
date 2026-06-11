
#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000
#define INF 1000000000000000
#define ll long long
#define ull unsigned long long
#define M (int)(1e9+7)
#define P pair<int,int>
#define PLL pair<ll,ll>
#define FOR(i,m,n) for(int i=(int)m;i<(int)n;i++)
#define RFOR(i,m,n) for(int i=(int)m;i>=(int)n;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,n,0)
#define all(a) a.begin(),a.end()
#define IN(a,n) rep(i,n){ cin>>a[i]; }
const int vx[4] = {0,1,0,-1};
const int vy[4] = {1,0,-1,0};
#define PI 3.14159265
#define F first
#define S second
#define PB push_back
#define EB emplace_back
void init(){
  cin.tie(0);
  ios::sync_with_stdio(false);
}




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
using WG = vector< Edges< T > >;
using UG = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;


vector<int> b;
bool binary_graph(UG es){
  b.resize(es.size());
  b[0]=1;
  queue<int> q;
  q.push(0);
  while(!q.empty()){
    int x=q.front();
    q.pop();
    for(auto e:es[x]){
      if(b[e]==0){
        b[e]=-1*b[x];
        q.push(e);
      }
      else if(b[e]*b[x]==1)
        return false;
    }
  }
  return true;
}

int main(){
  ll n,m;
  cin>>n>>m;
  UG es(n);
  rep(i,m){
    int a,b;
    cin>>a>>b;
    a--;
    b--;
    es[a].PB(b);
    es[b].PB(a);
  }

  if(binary_graph(es)){
    ll x=count(all(b),1);
    ll y=count(all(b),-1);
    cout<<x*y-m<<endl;
  }
  else
    cout<<n*(n-1)/2-m<<endl;
}
