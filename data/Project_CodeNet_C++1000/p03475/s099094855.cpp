#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve() {
  int n;
  cin >> n;
  vector<ll> c(n-1), s(n-1), f(n-1);
  rep(i,n-1) cin >> c[i] >> s[i] >> f[i];
  vector<ll> ans(n);
  rep(i,n - 1) {
    ll temp = 0;
    for (int j = i; j < n - 1; j++) {
      if (temp < s[j]) temp = s[j];
      if (temp % f[j] != 0) temp += f[j] - temp % f[j];
      temp += c[j];
    }
    ans[i] = temp;
  }
  rep(i,n) cout << ans[i] << endl;
}

int main() {
  solve();
  return 0;
}