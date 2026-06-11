#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
  int n;
  cin>>n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  int ans = __gcd(a[0],a[1]);
  rep(i,n) {
    ans = __gcd(ans, a[i]);
  }
  cout << ans << endl;
  return 0;
}