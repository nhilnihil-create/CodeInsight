#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define ll long long

signed main() {
  int N; cin >> N;
  vector<int> A(N);
  rep(i, N) cin >> A[i];

  vector<ll> dpa(N, 0), dpb(N, 0);
  dpa[0] = A[0];
  dpb[0] = -A[0];
  
  rep(i, N-1) {
    dpa[i+1] = max(dpa[i]+A[i+1], dpb[i]-A[i+1]);
    dpb[i+1] = max(dpa[i]-A[i+1], dpb[i]+A[i+1]);
  }
  
  cout << dpa[N-1] << endl;


}