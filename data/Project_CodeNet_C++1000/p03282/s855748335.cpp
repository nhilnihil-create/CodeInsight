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
  int k;
  cin >> k;
  int i = 0;
  for(;;) {
    if (i >= k || i >= s.size()) {
      i--;
      break;
    }
    if (s[i] - '0' != 1) {
      break;
    }
    i++;
  }
  cout << s[i] - '0' << endl;
}

int main() {
  solve();
  return 0;
}