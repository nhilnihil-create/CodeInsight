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

const string ky = "keyence";
const int m = ky.size();

void solve() {
  string s;
  cin >> s;
  int n = s.size();
  for (int i = 1; i < n - 1; i++) {
    for (int j = i; j < n; j++) {
      string t = s.substr(0, i);
      string u = s.substr(j);
      if ((t + u) == ky) {
        cout << "YES" << endl;
        return;
      }
    }
  }
  cout << "NO" << endl;
}

int main() {
  solve();
  return 0;
}