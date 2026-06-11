
#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1e18;


vector<ll> col(100005);
vector<vector<P>> g(100005);


void dfs(int t, int p,int d){
//  cout<<"t"<<t<<"p"<<p<<"d"<<d<<endl;
  for(P T:g[t]){
    int to=T.first;
    if (to==p)continue;
    int dnow=d+T.second;
    if(dnow%2==0)col[to]=0;
    else col[to]=1;
    dfs(to,t,dnow);
  }
}

int main() {
  ll n;
  cin>>n;
  rep(i,n-1){
    ll u1,v1,w1;
    cin>>u1>>v1>>w1;
    u1--;v1--;
    g[u1].push_back(make_pair(v1,w1));
    g[v1].push_back(make_pair(u1,w1));
  }
  dfs(0,-1,0);
  rep(i,n)cout<<col[i]<<endl;
}
