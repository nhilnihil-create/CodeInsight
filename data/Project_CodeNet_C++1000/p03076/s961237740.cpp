#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i, s, n) for (int i = (s); i < (n); ++i)
#define rrep(i, n, g) for (int i = (n)-1; i >= (g); --i)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define len(x) (int)(x).size()
#define dup(x, y) (((x) + (y)-1) / (y))
#define pb push_back
#define Field(T) vector<vector<T>>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int add = 10;
  int ans = 0;
  rep (i,0,5) {
    int temp;
    cin >> temp;
    int mod = temp % 10;
    ans += temp - temp % 10;
    if (mod != 0) {
      ans += 10;
      add = min(add, mod);
    }
  }
  ans -= (10 - add);
  cout << ans << endl;
  return 0;
}