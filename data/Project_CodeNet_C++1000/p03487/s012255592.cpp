#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int,int> x;
  rep(i,n) {
    cin >> a[i];
    x[a[i]]++;
  }
  int ans = 0;
  rep(i,n) {
    if (x[a[i]] == -1) continue;
    if (x[a[i]] < a[i]) ans += x[a[i]];
    else if (x[a[i]] > a[i]) ans += x[a[i]] - a[i];
    x[a[i]] = -1; 
  }
  cout << ans << endl;
  return 0;
}