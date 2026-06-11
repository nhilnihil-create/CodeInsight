#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long ll;
typedef tuple<ll, int, int, int> t;
int main() {
  auto compare = [](t a,t b) {
    return get<0>(a)<get<0>(b);
  };
  priority_queue<t, vector<t>, decltype(compare)> q(compare);
  int x, y, z, K, e, f, g;
  cin >> x >> y >> z >> K;
  vector<ll> a(x), b(y), c(z);
  set<int> s;
  rep(i,x)
    cin >> a[i];
  rep(i,y)
    cin >> b[i];
  rep(i,z)
    cin >> c[i];
  sort(a.begin(), a.end(), greater<ll>());
  sort(b.begin(), b.end(), greater<ll>());
  sort(c.begin(), c.end(), greater<ll>());
  q.push(make_tuple(a[0] + b[0] + c[0], 0, 0, 0));
  while (K--) {
    t p = q.top();
    q.pop();
    cout << get<0>(p) << endl;
    e = get<1>(p);
    f = get<2>(p);
    g = get<3>(p);
    if (e < x - 1 && !s.count((e + 1) * y * z + f * z + g)) {
      q.push(make_tuple(a[e + 1] + b[f] + c[g], e + 1, f, g));
      s.insert((e + 1) * y * z + f * z + g);
    }
    if (f < y - 1 && !s.count(e * y * z + (f + 1) * z + g)) {
      q.push(make_tuple(a[e] + b[f + 1] + c[g], e, f + 1, g));
      s.insert(e * y * z + (f + 1) * z + g);
    }
    if (g < z - 1 && !s.count(e * y * z + f * z + g + 1)) {
      q.push(make_tuple(a[e] + b[f] + c[g + 1], e, f, g + 1));
      s.insert(e * y * z + f * z + g + 1);
    }
  }
  return 0;
}
