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
  int n; cin >> n;
  vector<vector<int>> g(n);
  for(int i=0;i<n-1;++i) {
    int a, b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  ll su = 0;
  vector<int> c(n);
  for(int i=0;i<n;++i) {
    cin >> c[i];
    su += c[i];
  }
  sort(c.begin(), c.end());
  reverse(c.begin(), c.end());
  su -= c[0];
  queue<int> que;
  vector<bool> sel(n);
  que.push(0);
  sel[0] = true;
  int num = 0;
  vector<int> ans(n);
  while(!que.empty()) {
    int now = que.front(); que.pop();
    ans[now] = c[num];
    num++;
    for(int i=0;i<(int)(g[now].size());++i) {
      int next = g[now][i];
      if(!sel[next]) {
        sel[next] = true;
        que.push(next);
      }
    }
  }
  cout << su << endl;
  printv(ans);
}
