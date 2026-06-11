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
  vector<int> A(N);
  rep(i,N)  cin >> A.at(i);

  vector<int> gcdl(N);
  vector<int> gcdr(N);
  gcdl.at(0)=0;
  REP(i,1,N)  gcdl.at(i)=gcd(gcdl.at(i-1),A.at(i-1));
  gcdr.at(N-1)=0;
  for(int i=N-2;i>=0;i--) gcdr.at(i)=gcd(gcdr.at(i+1),A.at(i+1));

  int ans=0;
  rep(i,N)  chmax(ans,gcd(gcdl.at(i),gcdr.at(i)));
  cout << ans << endl;


  return 0;
}