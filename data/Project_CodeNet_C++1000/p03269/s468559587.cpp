#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
int main() {
  cin.tie(0);
  cout << fixed << setprecision(10);
  ll l; cin >> l;
  l--;
  vector<vector<P>> g(20);
  int now = 1;
  int cnt = 0;
  for(int i=0;i<18;++i) {
    g[i].push_back({i+1, 0});
    g[i].push_back({i+1, now});
    cnt += 2;
    now <<= 1;
  }
  int tmp = now;
  g[0].push_back({19, 0});
  cnt++;
  now = 1;
  for(int i=0;i<19;++i) {
    if(l & (1<<i)) {
      g[i].push_back({19, now});
      cnt++;
      now = now + (1<<i);
    }
  }
  if(l & (1<<19)) {
    g[18].push_back({19, now});
    g[18].push_back({19, tmp + now});
    cnt += 2;
  }
  cout << 20 << " " << cnt << endl;
  for(int i=0;i<20;++i) {
    for(int j=0;j<(int)(g[i].size());++j) {
      cout << i+1 << " " << g[i][j].first+1 << " " << g[i][j].second << endl;
    }
  }
}
