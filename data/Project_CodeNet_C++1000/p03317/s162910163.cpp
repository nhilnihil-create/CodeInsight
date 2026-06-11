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
  ll N, K;
  cin >> N >> K;
  vl A(N);
  rep(i, N) cin >> A[i];

  ll ans = 1 + (N - K) / (K - 1) + ((N - K) % (K - 1) > 0 ? 1 : 0);

  cout << ans << endl;
  
  return 0;
}
