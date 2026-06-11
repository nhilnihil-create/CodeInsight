#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

int main(){
  int N, K;
  cin >> N >> K;
  vector<ll> H(N);
  rep(i, N) cin >> H[i];
  sort(H.begin(), H.end());

  ll ans = 1000000000;
  rep(i, N-K+1) ans = min(ans, H[i+K-1]-H[i]);
  cout << ans << endl;
}
