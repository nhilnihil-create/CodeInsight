#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

// AGC024 B - Backfront

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  vector<int> P(N);
  REP(i, N){
    cin >> P[i];
  }
  vector<int> PP(N+1, 0);
  REP(i, N){
    PP[P[i]] = PP[P[i]-1] + 1;
  }
  int res = 0;
  REP(i, N+1){
    res = max(res, PP[i]);
  }
  int ans = N - res;
  cout << ans << endl;
}