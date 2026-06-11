#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = a; i >= (b); --i)
#define trav(a, x) for(auto &a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;



int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  
  int n; cin >> n;
  vi a(n), b(n), c(n);
  rep(i,0,n) {
    cin >> a[i] >> b[i] >> c[i];
  }
  vi A(n), B(n), C(n);
  A[0] = a[0],  B[0] = b[0], C[0] = c[0];

  rep(i,1,n) {
    A[i] = a[i] + max(B[i - 1], C[i - 1]);
    B[i] = b[i] + max(A[i - 1], C[i - 1]);
    C[i] = c[i] + max(A[i - 1], B[i - 1]);
  }
  int res = max(A[n - 1], max(B[n - 1], C[n - 1]));
  cout << res;
}