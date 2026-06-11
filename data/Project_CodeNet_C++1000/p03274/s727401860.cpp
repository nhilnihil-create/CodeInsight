#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
int n, k, x[100001]; 
int main() {
  cin >> n >> k;
  rep(i,n) cin >> x[i];
  int ans = INF;
  for (int i = 0; i + k <= n; i++)
  {
    int l = x[i], r = x[i+k-1];
    int now = min(abs(r)+abs(r-l), abs(l)+abs(r-l));
    ans = min(ans, now);
  }
  cout << ans << endl;
  
    return 0;
}