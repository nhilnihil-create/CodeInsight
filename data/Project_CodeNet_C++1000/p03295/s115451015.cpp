#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n); i++)
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
using namespace std;
using ll = long long;
int INF = 1001001001;

int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> p(m);
  rep(i, m) cin >> p[i].second >> p[i].first;
  sort(p.begin(), p.end());
  int cur = p[0].first - 1;
  int ans = 1;
  rep(i, m) {
    if(p[i].second <= cur) {
      continue;
    } else {
      cur = p[i].first - 1;
      ans++;
    }
  }
  cout << ans << endl;

  return 0;
}