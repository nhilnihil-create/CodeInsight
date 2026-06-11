#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  ll N, A, B, C, D, E;
  cin >> N >> A >> B >> C >> D >> E;
  ll mn = min({A, B, C, D, E});
  ll ans = (N + mn - 1) / mn + 4;
  cout << ans << endl;
  return 0;
}
