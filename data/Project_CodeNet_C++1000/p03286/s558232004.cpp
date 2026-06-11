#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void) {
  ll N;
  cin >> N;

  string ans = "";
  if (N == 0) {
    cout << 0 << endl;
    return 0;
  }
  while (N != 0) {
    if (N % 2 != 0) {
      N--;
      ans = "1" + ans;
    } else {
      ans = "0" + ans;
    }
    N /= -2;
  }

  cout << ans << endl; 
  return 0;
}