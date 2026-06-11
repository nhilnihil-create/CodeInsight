#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N, Y;
  cin >> N >> Y;
  rep(i, N + 1){
    rep(j, N + 1 - i){
      if(10000 * i + 5000 * j + 1000 * (N - i - j) == Y){
        cout << i << " " << j << " " << N - i - j << endl;
        return 0;
      }
    }
  }
  cout << -1 << " " << -1 << " " << -1 << endl;
  return 0;
}
