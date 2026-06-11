#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep_inv(i, n, m) for(int i = (int)(n); i > (int)(m); i--)
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vc = vector<char>;
using vvl = vector<vl>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

int main(){
  ll N, M;
  cin >> N >> M;
  vl X(M);
  rep(i, M) cin >> X[i];

  if(N >= M){
    cout << 0 << "\n";
    return 0;
  }

  stable_sort(X.begin(), X.end());

  vl Y(M - 1);
  ll ans = 0;
  rep(i, M - 1){
    Y[i] = X[i + 1] - X[i];
    ans += Y[i];
  }

  stable_sort(Y.begin(), Y.end(), greater<ll>());

  rep(i, N - 1) ans -= Y[i];

  cout << ans << "\n";
  
  return 0;
}
