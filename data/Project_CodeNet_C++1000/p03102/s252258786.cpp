#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  int N, M, C;
  cin >> N >> M >> C;
  vector<int> B(M);
  rep(i, M) cin >> B[i];
  int ans = 0;
  rep(i, N) {
    int tmp = C;
    rep(j, M) {
      int A;
      cin >> A;
      tmp += A * B[j];
    }
    if (tmp > 0) ans++;
  }
  cout << ans << endl;
}