#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
const double eps = 1e-10;
const int MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1ll<<50;
template<typename T>
void printv(const vector<T>& s) {
  for(int i=0;i<(int)(s.size());++i) {
    cout << s[i];
    if(i == (int)(s.size())-1) cout << endl;
    else cout << " ";
  }
}
bool operator< (const string &s1, const string &s2) {
  if(s2 == "*") {
    return false;
  } else if(s1 == "*") {
    return true;
  } else if((int)(s1.size()) == (int)(s2.size())) {
    for(int i=0;i<(int)(s1.size());++i) {
      if(s1[i] != s2[i]) {
        return s1[i] < s2[i];
      }
    }
    return false;
  } else {
    return (int)(s1.size()) < (int)(s2.size());
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  vector<int> v = {0, 2, 5, 5, 4, 5, 6, 3 ,7, 6};
  int n, m; cin >> n >> m;
  vector<int> a(m);
  for(int i=0;i<m;++i) {
    cin >> a[i];
  }
  vector<string> dp(n+1, "*");
  dp[0] = "";
  for(int i=0;i<n;++i) {
    if(dp[i] == "*") continue;
    for(int j=0;j<m;++j) {
      if(i + v[a[j]] > n) continue;
      if(dp[i+v[a[j]]] < dp[i] + to_string(a[j])) {
        dp[i+v[a[j]]] = dp[i] + to_string(a[j]);
      }
    }
  }
  cout << dp[n] << endl;
}
