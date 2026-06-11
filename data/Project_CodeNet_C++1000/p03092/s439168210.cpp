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

ll INF = 1000000000000000000;
int main(int argc, char const *argv[]) {
  ll n, A, B;std::cin >> n >> A >> B;
  vll p(n);re(i, n) scanf("%lld", &p[i]);
  vll idx(n+1); for(int i=0;i<n;i++) idx[p[i]] = i+1;
  vvl dp = VV(n+1, 2*n+2, INF, ll);

  vll prev(2*n+2, 0);
  for(int i=1;i<=n;i++){
    for(int j=1;j<2*n+2;j++){
      if(j==2*idx[i]){
        dp[i][j] = min(dp[i][j], prev[j-1]);
      }else if(j%2==0){
        dp[i][j] = min(dp[i][j], prev[j-1]+ (j<2*idx[i]?B:A));
      }else{
        dp[i][j] = min(dp[i][j], prev[j] + (j<2*idx[i]?B:A));
      }
    }
    for(int j=0;j<2*n+2;j++) prev[j] = INF;
    for(int j=1;j<2*n+2;j++) prev[j] = min(prev[j-1], dp[i][j]);
  }

  ll ans = INF;
  for(int i=1;i<2*n+2;i++) ans = min(ans, dp[n][i]);
  std::cout << ans << '\n';
  return 0;
}
