#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  ll INF = Mod * 100;
  ll N;
  cin >> N;
  ll F[N][10];
  ll P[N][11];
  ll ans = -INF;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 10; j++) {
      cin >> F[i][j];
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 11; j++) {
      cin >> P[i][j];
    }
  }

  for (int bit = 1; bit < (1 << 10); bit++) {
    ll res = 0;
    for (int i = 0; i < N; i++) {
      int cnt = 0;
      for (int j = 0; j < 10; j++) {
        if (bit & (1 << j)) {
          if (F[i][j] == 1) {
            cnt++;
          }
        }
      }
      res += P[i][cnt];
    }
    ans = max(ans,res);
  }
  cout << ans << endl;
  return 0;
}