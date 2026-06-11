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
#define uniq(x) ((x).erase(unique(all(x)),(x).end()))
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


int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int N;
  cin >> N;

  vector<int> cnt(101,0);
  REP(i,1,N+1){
    int tmp=i;
    REP(j,2,tmp+1){
      while(tmp%j==0){
        tmp/=j;
        cnt.at(j)++;
      }
    }
  }

  //3,5,15,25,75
  vector<int> X(5,0);
  rep(i,101){
    int tmp=cnt.at(i);
    if(tmp>=3-1)  X.at(0)++;
    if(tmp>=5-1)  X.at(1)++;
    if(tmp>=15-1)  X.at(2)++;
    if(tmp>=25-1)  X.at(3)++;
    if(tmp>=75-1)  X.at(4)++;
  }

  int ans=0;
  //3,5,5
  ans+=X.at(1)*(X.at(1)-1)/2 * (X.at(0)-2);
  //3.25
  ans+=X.at(3)*(X.at(0)-1);
  //5,15
  ans+=X.at(2)*(X.at(1)-1);
  //75
  ans+=X.at(4);
  cout << ans << endl;

  return 0;
}