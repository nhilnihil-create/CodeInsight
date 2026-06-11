#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second
#define m_p make_pair
#define p_b push_back
#define e_b emplace_back
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())

#define REP(i,m,n) for(int i=(int)(m);i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)

#ifdef LOCAL//compile with -DLOCAL
#define debug(x) cerr<<"LINE"<<__LINE__<<" : "<<#x<<" = "<<(x)<<endl
#define debug_vec(x) cerr<<"LINE"<<__LINE__<<" : "<<#x<<" = ";\
  rep(i,sz(x)){cerr<<x[i]<<" ";}cerr<<endl
#define debug_mat(x) cerr<<"LINE"<<__LINE__<<" : "<<#x<<" = "<<endl;\
  rep(i,sz(x)){rep(j,sz(x[i])){cerr<<x[i][j]<<" ";}cerr<<endl;}cerr<<endl
#else
#define debug(x) void(0)
#define debug_vec(x) void(0)
#define debug_mat(x) void(0)
#endif

template<class T> bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<class T> bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}


int N;
vector<vector<pair<int,int>>> graph(N);
vector<int> ans;

void dfs(int v,int p){
  if(p==-1) ans.at(v)=0;

  rep(i,sz(graph.at(v))){
    int nv=graph.at(v).at(i).fi;
    int c=graph.at(v).at(i).se %2;
    if(nv==p) continue;
    if(c==0)  ans.at(nv)=ans.at(v);
    else  ans.at(nv)=ans.at(v)^1;
    dfs(nv,v);
  }
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  cin >> N;
  graph.resize(N);
  rep(i,N-1){
    int u,v,w;
    cin >> u >> v >> w;
    u--;
    v--;
    graph.at(u).p_b(m_p(v,w));
    graph.at(v).p_b(m_p(u,w));
  }

  ans.resize(N);
  dfs(0,-1);
  rep(i,N)  cout << ans.at(i) << endl;

  return 0;
}