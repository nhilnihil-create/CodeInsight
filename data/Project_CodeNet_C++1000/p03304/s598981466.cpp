#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#define vll vector<ll>
#define vvv vector<vvl>
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> >
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvvl(a, b, c, d) vector<vvl>(a, vvl(b, vll (c, d)));
#define rep(c, a, b) for(ll c=a;c<b;c++)
#define re(c, b) for(ll c=0;c<b;c++)
#define all(obj) (obj).begin(), (obj).end()
typedef long long int ll;
typedef long double ld;
//typedef __int128_t lll;
using namespace std;

int main(int argc, char const *argv[]) {
  ld n, m, d;std::cin >> n >> m >> d;
  // 2*n-2
  ld ans = 2.0;
  ans *= (m-(ld)1.0)*(n-d);
  ans /= n*n;
  if(d==0) ans/=2.0;

  std::cout << fixed << setprecision(20) << ans << '\n';
  return 0;
}
