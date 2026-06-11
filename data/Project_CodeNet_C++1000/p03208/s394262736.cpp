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
  vl h(N);
  rep(i, N) cin >> h[i];

  stable_sort(h.begin(), h.end());

  ll ans = (ll)pow(10, 17);

  rep(i, N - K + 1)
    ans = min(ans, h[i + K - 1] - h[i]);

  cout << ans << "\n";
  
  return 0;
}
