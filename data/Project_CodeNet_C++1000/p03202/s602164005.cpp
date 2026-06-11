#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod = 1000000007;
//const ll mod = 998244353;
const int inf = 1e9 + 10;
const ll INF = 1e18;
const ld EPS = 1e-10;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }



int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(25);

  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  int left = 0, right = n;
  while (right - left > 1) {
    int mid = (left + right) / 2;
    map<int, int> mp;
    bool f = true;
    rep(i, n - 1) {
      if (a[i] >= a[i + 1]) {
        int res = a[i + 1];
        while (mp.size() && mp.rbegin()->first > res) {
          mp.erase(mp.rbegin()->first);
        }
        if (mp[res] == 0 && mid == 1) {
          f = false;
          break;
        }
        ++mp[res];
        while (mp[res] == mid) {
          mp[res] = 0;
          --res;
          if (res == 0) {
            f = false;
            break;
          }
          ++mp[res];
        }
      }
      if (!f) break;
    }
    if (f) right = mid;
    else left = mid;
  }
  cout << right << '\n';

  




  
  return 0;
}
