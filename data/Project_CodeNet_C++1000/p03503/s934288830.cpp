#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define reps(i,n) for (int i=1;i<=(n);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
#define rreps(i,n) for (int i=(n);i>0;i--)
#define all(v) (v).begin(),(v).end()
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>
template<class T> inline bool chmin(T &a, T b) {if (a>b) {a = b; return 1;} return 0;};
template<class T> inline bool chmax(T &a, T b) {if (a<b) {a = b; return 1;} return 0;};
typedef long long int ll;
const long long INF = 1LL << 60;


int main(){
  int N; cin >> N;
  bool F[N][5][2]; rep(i,N) rep(j,5) rep(k,2) cin >> F[i][j][k];
  ll P[N][11]; rep(i,N) rep(j,11) cin >> P[i][j];

  ll ans = -INF;
  for (ll tmp=1;tmp<(1LL<<10);tmp++){
    bitset<10> s(tmp);
    
    vector<int> c(N,0);
    rep(j,N) rep(d,5) rep(t,2){
      int i = 2*d + t;
      if (s.test(i) && F[j][d][t]==1) c[j]++;
    }
    ll b = 0;
    rep(j,N) b += P[j][c[j]];
    ans = max(ans, b);
  }
  cout << ans << endl;




  // cout << fixed << setprecision(10);
  
  return 0;
}
