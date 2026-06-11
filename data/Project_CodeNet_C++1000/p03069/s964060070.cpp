#include <bits/stdc++.h>

#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef long long ll;
typedef pair<int,int> P;
const long long LINF = 1001002003004005006ll;
const int INF = 1001001001;
const int mod = 1000000007;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(20) << fixed;

  int n; cin >> n;
  string s; cin >> s;

  int ans = INF;
  // black := [, i) の黒の個数
  // white := [i, ) を白の個数
  int white = count(s.begin(), s.end(), '.'), black = 0;
  ans = min(ans, white+black);
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '.') {
      white--;
    } else {
      black++;
    }
    ans = min(ans, white+black);
  }
  cout << ans << endl;
  return 0;
}