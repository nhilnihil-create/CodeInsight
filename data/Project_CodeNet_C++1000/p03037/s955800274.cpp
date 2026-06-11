#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;
using M = map<int, int>;

int main()
{
  int n, m;
  cin >> n >> m;
  int a[n];
  rep(i, n) a[i] = 0;
  int x, y;
  int mi = 0, ma = 100005;
  rep(i, m){
    cin >> x >> y;
    mi = max(mi, x);
    ma = min(ma, y);
  }
  int ans = ma - mi + 1;
  if(ans < 0) ans = 0;
  cout << ans << endl;

  return 0;
}
