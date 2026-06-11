#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define ALL(a) (a).begin(), (a).end()
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using Graph = vector<vi>;
using P = pair<int, int>;
const int MOD = 1e9+7;
const double EPS = 1e-9;

int mod;
vi use(8), res, adjustment;

void dfs(const int n, map<int, Graph> &G, vi &order, int &sum) {
  for (auto v : adjustment) {
    sum += v;
    order.push_back(use[v+mod]);

    if (order.size() * mod + sum <= n) {
      if (res[sum%mod] > sum) {
        res[sum%mod] = sum;
        G[sum%mod] = Graph(1, order);
        dfs(n, G, order, sum);
      }

      else if (res[sum%mod] == sum) {
        G[sum%mod].push_back(order);
        dfs(n, G, order, sum);
      }
    }

    sum -= v;
    order.pop_back();
  }
}

int main() {
  int n, m; cin >> n >> m;
  vi a(m);
  rep(i,m) cin >> a[i];
  
  vi match = {0,2,5,5,4,5,6,3,7,6};
  set<int> stick;
  for (auto v : a) {
    use[match[v]] = max(use[match[v]], v);
    stick.insert(match[v]);
  }

  mod = *begin(stick);

  if (n%mod == 0) {
    rep(i,n/mod) cout << use[mod];
    cout << endl;
    return 0;
  }

  stick.erase(mod);
  for (auto v : stick) adjustment.push_back(v-mod);
  res.assign(mod, 100);
  res[0] = 0;

  int sum = 0;
  map<int, Graph> G;
  vi order;

  dfs(n, G, order, sum);

  int r = min(mod-1, (n-res[n%mod])/mod);
  for (auto &vec : G[n%mod]) {
    int sz = vec.size();
    sz = min(sz, mod-1);
    rep(i,r-sz) vec.push_back(use[mod]);
    sort(ALL(vec), greater<int>());
  }

  vi ans(r, 0);

  for (auto vec : G[n%mod]) {
    rep(i,r) {
      if (ans[i] < vec[i]) {
        ans = vec;
        break;
      }
      if (ans[i] > vec[i]) break;
    }
  }

  rep(i,(n-res[n%mod])/mod-r) ans.push_back(use[mod]);
  sort(ALL(ans), greater<int>());
  for (auto p : ans) cout << p;
  cout << endl;
  return 0;
}
