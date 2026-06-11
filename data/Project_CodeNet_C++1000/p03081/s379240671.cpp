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
  int N,Q;
  cin >> N >> Q;
  string S;
  cin >> S;
  S='.'+S+'.';
  N+=2;
  vector<char> t(Q);
  vector<char> d(Q);
  rep(i,Q)  cin >> t.at(i) >> d.at(i);
  reverse(all(t));
  reverse(all(d));

  int l=0;
  int r=N-1;
  rep(i,Q){
    if(d.at(i)=='L'){
      if(S.at(l+1)==t.at(i))  l++;
      if(S.at(r)==t.at(i))  r++;
    }
    else if(d.at(i)=='R'){
      if(S.at(l)==t.at(i))  l--;
      if(S.at(r-1)==t.at(i))  r--;
    }
    if(l+1>=r){
      cout << 0 << endl;
      return 0;
    }
  }
  cout << r-1-l << endl;

  return 0;
}