#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
using namespace std;
using namespace __gnu_pbds;
using ll = int64_t;
using ld = long double;
using ull = uint64_t;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

string s;

ll x, y;

const ll HOR = 1;
const ll VER = 0;

vector<ll> m[2];

bool solve(ll val, vector<ll> v) {
  set<ll> possible = {0};
  for (ll x: v) {
    set<ll> nxt;
    for (ll p: possible) {
      nxt.insert(p+x);
      nxt.insert(p-x);
    }
    possible = nxt;
  }
  return possible.find(val) != possible.end();
}

int main() {
  ios::sync_with_stdio(0);
  cout.precision(10);
  cin >> s;
  cin >> x >> y;
  int pos = 0;
  while(pos < s.size() && s[pos] == 'F') {
    pos++;
  }
  x -= pos;
  ll dir = HOR;
  
  ll cur = 0;
  while(pos < s.size()) {
    if (s[pos] == 'T') {
      if (cur > 0) {
        m[dir].push_back(cur);
      }
      dir = !dir;
      cur = 0;
    } else {
      cur++;
    }
    pos++;
  }

  if (cur > 0) {
    m[dir].push_back(cur);
  }

  /*cerr << "NEW x, y: " << x << ", " << y << endl;
  cerr << "HOR: " << endl;
  for (auto x: m[HOR])
    cerr << x << ' '; cerr << endl;
  cerr << "VERT: " << endl;
  for (auto x: m[VER])
    cerr << x << ' '; cerr << endl;
    */
  
  if (solve(x, m[HOR]) && solve(y, m[VER])) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}