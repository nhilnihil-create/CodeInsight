#include <bits/stdc++.h>

using namespace std;

#define SZ(x) (int)(x.size())

using ll = long long;
#define int ll
using ld = long double;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
const ld eps = 1e-9;
const ll MOD = 1000000007;
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

template<typename T1, typename T2>
ostream& operator<<(ostream &os, const pair<T1, T2> p) {
  os << p.first << ":" << p.second;
  return os;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  int n; cin >> n;
  vector<P> v(n);
  for(int i=0;i<n;++i) {
    cin >> v[i].first >> v[i].second;
  }
  sort(v.begin(), v.end(), [](P p1, P p2){return (p1.first + p1.second) > (p2.first + p2.second);});
  int taka = 0, ao = 0;
  for(int i=0;i<n;++i) {
    if(i%2 == 0) taka += v[i].first;
    else ao += v[i].second;
  }
  cout << taka - ao << endl;

}
