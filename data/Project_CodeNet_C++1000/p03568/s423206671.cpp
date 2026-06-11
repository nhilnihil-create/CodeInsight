#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  ll N;
  cin >> N;
  ll ans = 1;
  ll ans2 = 1;
  ll X;
  rep(i, N) {
    cin >> X;
    if(X % 2 == 0) {
      ans2 *= 2;
    }
    else {
      ans2 *= 1;
    }
    ans *= 3;
  }
  cout << ans - ans2 << endl;
}