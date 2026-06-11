#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#define vll vector<ll>
#define vvvl vector<vvl>
#define vvl vector<vector<ll>>
#define VV(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define VVV(a, b, c, d) vector<vvl>(a, vvl(b, vll (c, d)));
#define re(c, b) for(ll c=0;c<b;c++)
#define all(obj) (obj).begin(), (obj).end()
typedef long long int ll;
typedef long double ld;
using namespace std;

ll INF = 1000000000000000;
// a rateがa下がる
// b rateがb以上である必要あり
int main(int argc, char const *argv[]) {
  ll n;std::cin >> n;
  vvl d = VV(n, 4, 0, ll);
  for(int i=0;i<n;i++){
    ll a, b, c;scanf("%lld %lld %lld", &a, &b, &c);
    d[i][0] = a, d[i][1] = b, d[i][2] = c, d[i][3] = a - (INF - b);
  }
  sort(all(d), [](vll x, vll y){return x[3] < y[3];});
  //for(auto v:d) std::cout << v[0] << " " << v[1] << '\n';

  vvl dp = VV(n+1, 10002, -INF, ll);
  dp[0][0] = 0;
  for(int i=0;i<n;i++){
    for(ll j=0;j<=10001;j++){
      dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
      if(d[i][1]<j||j==10001) continue;
      ll nxt = (j+d[i][0]>10000?10001:j+d[i][0]);
      dp[i+1][nxt] = max(dp[i+1][nxt], dp[i][j] + d[i][2]);
    }
  }
  ll ans = 0;
  for(int i=0;i<=10001;i++) ans = max(ans, dp[n][i]);
  std::cout << ans << '\n';
  return 0;
}
