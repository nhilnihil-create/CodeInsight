#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
ll d[100005];
struct wtf {
  int ds, x, d;
  const bool operator<(const wtf &e) const {
    return ds == e.ds ? d > e.d : ds > e.ds;
  }
};
int main() {
  ll n;
  cin >> n;
  fill(d, d + 100005, INF);
  priority_queue<wtf> q;
  for (int i = 1; i <= 9; i++)
    q.push({i, i, 1}), d[i] = i;
  d[0] = INF;
  while (!q.empty()) {
    wtf u = q.top();
    q.pop();
    for (int i = 0; i <= 9; i++) {
      int nds = u.ds + i, nnum = (u.x * 10 + i) % n, nd = u.d + 1;
      wtf nu = {nds, nnum, nd};
      if (d[nu.x] > d[u.x] + i) {
        q.push(nu);
        d[nu.x] = d[u.x] + i;
      }
    }
  }
  cout << d[0] << endl;
}