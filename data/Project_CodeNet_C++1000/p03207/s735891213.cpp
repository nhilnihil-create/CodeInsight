#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using ll = long long;
using P = pair<int, int>;
#define debug(var) cout << "[" << #var << "] " << var << endl
const ll mod = 1000000007;
 
int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  rep(i, n) cin >> p[i];
  sort(p.begin(), p.end());
  int ans = 0;
  p.back() /= 2;
  rep(i, n) {
    ans += p[i];
  }
  cout << ans << endl;
  return 0;
}