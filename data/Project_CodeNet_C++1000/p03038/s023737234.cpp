#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
int main(){
  ll N, M; cin >> N >> M;
  vector<ll> A(2*N, 0); rep(i, N) cin >> A.at(i);
  vector<pair<ll,ll>> CB(M); rep(i, M) cin >> CB.at(i).second >> CB.at(i).first;
  sort(all(CB));
  ll n = 0;
  ll m = M-1;
  while(n < N && m >= 0){
    rep(i, CB.at(m).second){
      A.at(N+n) = CB.at(m).first;
      n++;
      if(n>=N) break;
    }
    m--;
  }
  sort(all(A));
  reverse(all(A));
  ll ans = 0;
  rep(i, N) ans += A.at(i);
  cout << ans << endl;
  return 0;
}
