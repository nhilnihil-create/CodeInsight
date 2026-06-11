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
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = 0;
  rep(i, n-1) {
    string x = s.substr(0, i+1);
    string y = s.substr(i+1);
    vector<int> a(26), b(26);
    rep(j,x.size()) {
      a[x[j] - 'a']++;
    }
    rep(j,y.size()) {
      b[y[j] - 'a']++;
    }
    int temp = 0;
    rep(i,26) {
      if (a[i] && b[i]) temp++;
    }
    ans = max(ans, temp);
  }
  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}