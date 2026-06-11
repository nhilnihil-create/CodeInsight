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


int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  string S;
  cin >> S;

  if(sz(S)!=26){
    vector<bool> used(26,false);
    rep(i,sz(S))  used.at(S.at(i)-'a')=true;
    rep(i,26){
      if(used.at(i))  continue;
      S+=char(i+'a');
      break;
    }
    cout << S << endl;
    return 0;
  }
  bool flag=true;
  rep(i,26) if(S.at(i)!='z'-i)  flag=false;
  if(flag){
    cout << -1 << endl;
    return 0;
  }

  vector<bool> used(26,false);
  for(int i=26-1;i>=0;i--){
    int now=S.at(i)-'a';
    used.at(now)=true;
    if(i==25) continue;
    if(S.at(i)<S.at(i+1)){
      string ans="";
      rep(j,i)  ans+=S.at(j);
      REP(j,now+1,26){
        if(used.at(j)){
          ans+=char(j+'a');
          break;
        }
      }
      cout << ans << endl;
      return 0;
    }
  }

  return 0;
}