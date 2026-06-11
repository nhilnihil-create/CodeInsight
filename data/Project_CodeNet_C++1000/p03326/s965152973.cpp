#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, M; cin >> N >> M;
  vector<ll> x(N, 0);
  vector<ll> y(N, 0);
  vector<ll> z(N, 0);
  REP(i, N){
    cin >> x[i] >> y[i] >> z[i];
  }
  vector<ll> xyz(N, 0);
  ll ans = 0;
  for(ll i = -1; i <= 1; i += 2){
    for(ll j = -1; j <= 1; j += 2){
      for(ll k = -1; k <= 1; k += 2){
        ll res = 0;
        REP(l, N){
          xyz[l] = i*x[l] + j*y[l] + k*z[l];
        }
        sort(xyz.begin(), xyz.end(), greater<ll>());
        REP(l, M){
          res += xyz[l];
        }
        ans = max(ans, res);
      }
    }
  }
  cout << ans << endl;
}