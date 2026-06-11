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

int main(int argc, char const *argv[]) {
  ll n;std::cin >> n;
  vll a(n), b(n);
  multimap<ll, ll> mp;
  re(i, n) {
    std::cin >> a[i] >> b[i];
    mp.emplace(a[i] + b[i], i);
  }
  ll A = 0, B = 0;
  while(!(mp.empty())){
    ll idx = (*(--mp.end())).second;
    A+=a[idx];mp.erase(--mp.end());
    if(mp.empty()) break;
    idx = (*(--mp.end())).second;
    B+=b[idx];mp.erase(--mp.end());
    //std::cout << A << " " << B << '\n';
  }
  std::cout << A - B << '\n';
  return 0;
}
