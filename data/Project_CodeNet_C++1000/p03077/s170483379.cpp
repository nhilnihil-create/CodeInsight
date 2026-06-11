#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
  //ll n,a,b,c,d,e;
  //cin>>n>>a>>b>>c>>d>>e;
  ll num[6];
  rep(i,6) cin >> num[i];
  ll n = num[0];
  sort(num, num+6);
  ll ans = n / num[0];
  if (n % num[0] != 0) ans++;
  cout << ans+4 << endl;
  return 0;
}