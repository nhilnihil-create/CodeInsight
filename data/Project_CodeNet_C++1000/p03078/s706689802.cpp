#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
using ll = long long;
#define chmin(i, j) i = min(i, j);
#define chmax(i, j) i = max(i, j);
#define rep(i, n) for(int i=0;i<n;i++)
int main() {
  int x, y, z, K;
  cin >> x >> y >> z >> K;
  vector<ll> a(x), b(y), c(z);
  rep(i, x) cin >> a[i];
  rep(i, y) cin >> b[i];
  rep(i, z) cin >> c[i];
  sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());
  sort(c.rbegin(), c.rend());
  auto cmp = [](vector<ll> first, vector<ll> second) { return first[0] < second[0]; };
  priority_queue<ll, vector<vector<ll>>, decltype(cmp)> pq(cmp);
  map<vector<ll>, int> mp;
  vector<ll> d({a[0]+b[0]+c[0], 0, 0, 0});
  pq.emplace(d);
  mp[d]++;
  for(int it=0;it<K;it++) {
    vector<ll> v = pq.top();pq.pop();
    cout << v[0] << endl;
    ll i = v[1], j = v[2], k = v[3];
    vector<ll> p({a[(i+1)%x]+b[j]+c[k], i+1, j, k});
    vector<ll> q({a[i]+b[(j+1)%y]+c[k], i, j+1, k});
    vector<ll> r({a[i]+b[j]+c[(k+1)%z], i, j, k+1});
    if(!mp[p] && i+1 != x) {
      pq.emplace(p);
      mp[p]++;
    }
    if(!mp[q] && j+1 != y) {
      pq.emplace(q);
      mp[q]++;
    }
    if(!mp[r] && k+1 != z) {
      pq.emplace(r);
      mp[r]++;
    }
  }
  return 0;
}

