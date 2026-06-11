#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

signed main() {
  int N, M; cin >> N >> M;
  string S, T; cin >> S >> T;
  
  int g = gcd(N, M);
  int l = N/g*M;

  rep(i, M) {
    if((i*(l/M)*N)%l == 0 && T[i] != S[(i*(l/M)*N)/l]) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << l << endl;
}
