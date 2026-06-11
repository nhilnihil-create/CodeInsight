#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<vi> f(n,vi(10)); rep(i,n) rep(j,10) cin >> f[i][j];
  vector<vi> p(n,vi(11)); rep(i,n) rep(j,11) cin >> p[i][j];

  int ans = -1001001001;
  rep(bit,1<<10){
    if(bit == 0) continue;
    vi cnt(n);
    rep(i,10){
      if(bit>>i & 1){
        rep(j,n) cnt[j] += f[j][i];
      }
    }
    int res = 0;
    rep(i,n) res += p[i][cnt[i]];
    chmax(ans,res);
  }
  cout << ans;
  cout << "\n";
  return 0;
}
