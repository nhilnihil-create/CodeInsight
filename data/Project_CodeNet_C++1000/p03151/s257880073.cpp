#include <bits/stdc++.h>
#include <numeric>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
const long long MOD = 1e9+7;
#define precout(val) cout << std::fixed << std::setprecision(20) << val;
const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n; cin >> n;
  vector<int> A(n);
  vector<int> B(n);
  ll have = 0;
  rep(i, n) {
    cin >> A[i];
    have += A[i];
  }
  vector<int> S;
  ll need = 0;
  rep(i, n) {
    cin >> B[i];
    need += B[i];
    if(B[i] <= A[i]) {
      S.push_back(A[i] - B[i]);
    }
  }
  if(need > have) {
    cout << -1 << endl;
    return 0;
  }

  sort(S.begin(), S.end());
  int ans = n;

  rep(i, S.size()) {
    if(need + S[i] <= have) {
      need += S[i];
      --ans;
    }
  }

  cout << ans << endl;
  return 0;
}
