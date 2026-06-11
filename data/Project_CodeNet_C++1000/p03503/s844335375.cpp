#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second

#define bit(n,k) ((n>>k)&1) //*n no k bit me 1 or 0*/
 
const int mx=200010;
const ll mod=1e9+7;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> f(n, vector<int>(10));
  rep(i,n)rep(j,10) cin >> f[i][j];
  vector<vector<ll>> p(n, vector<ll>(11));
  rep(i,n)rep(j,11) cin >> p[i][j];

  ll ans = -longinf;
  for(int i=1; i<1024; i++){
    ll res = 0;
    rep(j,n){
      int cnt = 0;
      rep(k,10)if(f[j][k]==1 && bit(i,k)) cnt++;
      res += p[j][cnt];
    }
    ans = max(ans, res);
  }
  cout << ans << endl;
  return 0;
}