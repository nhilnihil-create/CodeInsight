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
  vector<string> s(n);
  rep(i,n) cin >> s[i];
  int m;
  cin >> m;
  vector<string> t(m);
  rep(i,m) cin >> t[i];
  map<string, int> count;
  rep(i,n) count[s[i]]++;
  rep(i,m) count[t[i]]--;
  int ans = 0;
  for (auto u: count) {
    ans = max(ans, u.second);
  }
  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}