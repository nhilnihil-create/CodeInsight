#include <bits/stdc++.h>

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep2(i, a, b) for (ll i = (a); i < (b); i++)
typedef uint64_t ull;
typedef int64_t ll;
typedef std::pair<ll, ll> PLL;

using namespace std;


signed main() {
  ll N;
  cin >> N;
  vector<string> s(N*4, string(N*4, '#'));

  rep(i,N) {
    string x;
    cin>>x;
    rep(j,N){
      s[i][j]=x[j];
      s[i+N][j]=x[j];
      s[i][j+N]=x[j];
      s[i+N][j+N]=x[j];
    }
  }
  //rep(i,2*N){
  //  rep(j,2*N){
  //    cout<<s[i][j];
  //  }
  //  cout<<endl;
  //}

  ll ans = 0;
  rep(dx,N) {
    bool ok = true;
    ll ox = N-dx, oy = N;
    rep(x,N) rep(y,N) {
      if (s[x+ox][y+oy] != s[y+ox][x+oy]){
        ok = false;
      }
    }
    if (ok)
      ans++;
  }
  ans *= N;
  cout << ans << endl;
  return 0;
}
