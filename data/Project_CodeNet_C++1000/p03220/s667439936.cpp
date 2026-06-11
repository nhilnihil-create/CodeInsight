#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;


int main(){
  ll N, T, A;
  cin >> N >> T >> A;
  vector<ll> H(N);

  rep(i, N) cin >> H[i];

  rep(i, N) H[i] = abs(T*1000 - H[i]*6 - A*1000);

  // Hがソートされていない時はdistanceを利用する
  auto index = min_element(H.begin(), H.end());
  int ans = index - H.begin();
  cout << ans + 1 << endl;
}
