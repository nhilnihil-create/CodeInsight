#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve() {
  string s;
  cin >> s;
  rep(bit, (1 << 3)) {
    int temp = (s[0] - '0');
    rep(i,3) {
      if (bit & (1 << i)) temp += (s[i+1] - '0');
      else temp -= (s[i+1] - '0');
    }
    if (temp == 7) {
      string ans = "";
      ans += s[0];
      rep(i,3) {
        if (bit & (1 << i)) ans += '+';
        else ans += '-';
        ans += s[i+1];
      }
      cout << ans + "=7" << endl;
      return;
    }
  }
}

int main() {
  solve();
  return 0;
}