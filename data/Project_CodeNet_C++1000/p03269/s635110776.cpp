#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define F first
#define S second

using namespace std;
using P = pair<int,int>;
using ivec = vector<int>;
using Graph = vector<vector<P>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }


const int MOD=1000000007;
int INF=100100100100100;
Graph g(20);

int cnt=0;
int dfs(int n){
  if(n==1)return 0;
  int v=dfs(n/2)+1;
  g[v-1].pb(P(v,0));
  g[v-1].pb(P(v,n/2));
  cnt+=2;
  if(n%2){g[0].pb(P(v,n-1));cnt++;}
  return v;
}
signed main(){
  int n;cin>>n;
  int ko=dfs(n)+1;
  cout<<ko<<" "<<cnt<<endl;
  rep(i,20){
    for(auto p:g[i])cout<<i+1<<" "<<p.F+1<<" "<<p.S<<endl;
  }
  return 0;
}
