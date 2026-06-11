#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void) {
  ll N, a;
  ll ans = 0;
  cin >> N;
  rep(i, N) {
    cin >> a;
    while (a % 2 == 0) {
      a /= 2;
      ans++;
    }
  }

  cout << ans << endl;
  
  return 0;
}