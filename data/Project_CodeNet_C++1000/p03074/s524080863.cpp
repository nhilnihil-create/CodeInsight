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
  int N,K;
  cin >> N >> K;
  string S;
  cin >> S;

  vector<int> cnt;
  if(S.at(0)=='0')  cnt.p_b(0);
  int tmp=1;
  REP(i,1,N){
    if(S.at(i)==S.at(i-1))  tmp++;
    else{
      cnt.p_b(tmp);
      tmp=1;
    }
  }
  cnt.p_b(tmp);
  if(S.at(N-1)=='0')  cnt.p_b(0);

  N=sz(cnt);
  vector<int> sum(N+1,0);
  REP(i,1,N+1)  sum.at(i)=sum.at(i-1)+cnt.at(i-1);
  int ans=0;
  for(int i=min(2*K+1,N);i<N+1;i+=2){
    chmax(ans,sum.at(i)-sum.at(max(0,i-(2*K+1))));
  }
  cout << ans << endl;

  return 0;
}