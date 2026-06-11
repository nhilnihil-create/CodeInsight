#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
using P = pair<int,int>;
using ll = long long;
const ll INF = 1LL<<60;

//cin.tie(0);ios::sync_with_stdio(false);
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  rep (i, m) cin >> a[i];
  vector<int> dis(m - 1);
  sort(a.begin(), a.end());
  rep (i, m - 1) dis[i] = abs(a[i] - a[i + 1]);

  vector<int> sorted_dis = dis;
  sort(sorted_dis.begin(), sorted_dis.end());
  reverse(sorted_dis.begin(), sorted_dis.end());

  ll ans = accumulate(dis.begin(), dis.end(), 0);
  for (int i = 0; i < n - 1 && i < m - 1; i++) ans -= sorted_dis[i];
  cout << ans << endl;
  return 0;
}
