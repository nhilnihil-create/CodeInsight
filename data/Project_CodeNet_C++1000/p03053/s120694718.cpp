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

vector<int> dy={1,0,-1,0};
vector<int> dx={0,1,0,-1};

int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int H,W;
  cin >> H >> W;
  vector<string> S(H);
  rep(i,H)  cin >> S.at(i);

  vector<vector<int>> dist(H,vector<int>(W,1e9));
  priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
  rep(i,H){
    rep(j,W){
      if(S.at(i).at(j)=='#'){
        dist.at(i).at(j)=0;
        pq.push(m_p(0,m_p(i,j)));
      }
    }
  }
  while(!pq.empty()){
    int c=pq.top().fi;
    int y=pq.top().se.fi;
    int x=pq.top().se.se;
    pq.pop();
    rep(i,4){
      int ny=y+dy.at(i);
      int nx=x+dx.at(i);
      if(ny<0 || ny>=H || nx<0 || nx>=W)  continue;
      int nc=c+1;
      if(dist.at(ny).at(nx)<=nc)  continue;
      dist.at(ny).at(nx)=nc;
      pq.push(m_p(nc,m_p(ny,nx)));
    }
  }
  int ans=0;
  rep(i,H){
    rep(j,W){
      chmax(ans,dist.at(i).at(j));
    }
  }
  cout << ans << endl;

  return 0;
}