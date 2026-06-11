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
  int N; cin >> N;
  vector<vector<int> > F(N, vector<int>(10, 0));
  REP(i, N){
    REP(j, 10){
      cin >> F[i][j];
    }
  }
  vector<vector<ll> > P(N, vector<ll>(11, 0));
  REP(i, N){
    REP(j, 11){
      cin >> P[i][j];
    }
  }
  ll ans = -1e18;
  REP(i, 1<<10){
    if(i == 0) continue;
    vector<int> cnt(N, 0);
    ll res = 0;
    REP(j, 10){
      if((i >> j)&1){
        REP(k, N){
          if(F[k][j]) cnt[k]++;
        }
      }
    }
    REP(j, N){
      res += P[j][cnt[j]];
    }
    ans = max(ans, res);
  }
  cout << ans << endl;
}
