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
  cout << fixed << setprecision(25);

  int n;
  cin >> n;

  string res;
  cout << 0 << endl;
  cin >> res;
  if (res == "Vacant") return 0;
  int left = 0, right = n;
  while (1) {
    int mid = (left + right) / 2;
    string nxt;
    cout << mid << endl;
    cin >> nxt;
    if (nxt == "Vacant") return 0;
    if (((mid - left) % 2 == 0 && res != nxt) || ((mid - left) % 2 == 1 && res == nxt)) right = mid;
    else {
      left = mid;
      res = nxt;
    }
  }



  
  return 0;
}