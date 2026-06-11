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
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> >
#define vll vector<ll>
#define rep(c, a, b) for(ll c=a;c<b;c++)
#define re(c, b) for(ll c=0;c<b;c++)
typedef long long int ll;
typedef long double ld;
using namespace std;
#include <iomanip>

int main(int argc, char const *argv[]) {
  ld ans = 0, n, m, d, k;std::cin >> n >> m >> d;
  if(d==0) k = n;
  else k = 2*n-2*d;
  ans = (k*(m-1))/(n*n);
  std::cout << fixed << setprecision(20) << ans << '\n';
  return 0;
}
