#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(int i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

int main() {
  int n;
  cin >> n;
  vector<vi> t(n);
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    t[a].push_back(b);
    t[b].push_back(a);
  }
  int root = 0;
  vi d(n, -1);
  rep(k, 2) {
    queue<int> q;
    q.push(root);
    d[root] = 0;
    while(!q.empty()) {
      int i = q.front();
      q.pop();
      for(int ni : t[i]) {
        if(d[ni] != -1) continue;
        d[ni] = d[i] + 1;
        q.push(ni);
      }
    }
    if(k == 1) continue;
    root = max_element(all(d)) - d.begin();
    d = vi(n, -1);
  }
  int l = *max_element(all(d));
  cout << (l % 3 == 1 ? "Second" : "First") << endl;
}