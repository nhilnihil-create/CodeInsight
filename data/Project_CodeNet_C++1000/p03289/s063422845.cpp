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
  int n = s.size();
  bool b1 = true;
  if (s[0] != 'A') b1 = false;

  int cnt1 = 0;
  for (int i = 2; i <= n - 2; i++) {
    if (s[i] == 'C') cnt1++;
  }
  bool b2 = false;
  if (cnt1 == 1) b2 = true;

  int cnt2 = 0;
  rep(i,n) {
    if (s[i] - 'A' >= 0 && s[i] - 'A' < 26) cnt2++;
  }
  bool b3 = false;
  if (cnt2 == 2) b3 = true;

  cout << ((b1 && b2 && b3)? "AC": "WA") << endl;
}

int main() {
  solve();
  return 0;
}