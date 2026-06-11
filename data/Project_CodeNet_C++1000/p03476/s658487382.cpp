#include <bits/stdc++.h>
using namespace std;

// ----------- define --------------
#define int long long
#define vi vector<int>
#define vc vector<char>
#define ii pair<int,int>
#define fi first
#define sc second
#define stoi stoll
#define all(x) (x).begin(),(x).end()
#define get_bit(x, k) ((x >> k) & 1)
// ---------------------------------

const int N = 1e5;

int prime[N + 1], f[N + 1];

void MAIN() {
  for (int i = 2; i <= N; i++) {
    prime[i] = 1;
  }
  for (int i = 2; i <= N; i++) {
    if (prime[i]) {
      for (int j = i * 2; j <= N; j += i) {
        prime[j] = 0;
      }
    }
  }
  for (int i = 2; i <= N; i++) {
    if (prime[i] && prime[(i + 1) / 2]) f[i] = 1;
    f[i] += f[i - 1];
  }
  int q; cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << f[r] - f[l - 1] << '\n';
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
