#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  int ans = 0;
  rep(i, N) {
    cin >> a[i];
    while (a[i] % 2 == 0) {
      a[i] /= 2;
      ans++;
    };
  }
  cout << ans << endl;

  return 0;
}
