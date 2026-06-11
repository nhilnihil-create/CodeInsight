#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using VLL = vector<ll>;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M; cin >> N >> M;
  vector<VLL> v(N, VLL(3));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> v[i][j];
    }
  }
  
  ll ans = 0;
  for (int i = 0; i < 8; i++) {
    sort(v.begin(), v.end(), [&i](VLL a, VLL b) {
      ll suma = 0, sumb = 0;
      for (int j = 0; j < 3; j++) {
        suma += (i & 1 << j) ? a[j] : -a[j];
        sumb += (i & 1 << j) ? b[j] : -b[j];
      }
      return suma > sumb;
    });
    VLL res(3);
    for (int j = 0; j < M; j++) {
      for (int k = 0; k < 3; k++) {
        res[k] += v[j][k];
      }
    }
    ans = max(ans, abs(res[0]) + abs(res[1]) + abs(res[2]));
  }
  cout << ans << "\n";
}