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
#define all(obj) (obj).begin(), (obj).end()
typedef long long int ll;
typedef long double ld;
using namespace std;
int main(int argc, char const *argv[]) {
  vll a(5, 0);
  ll x, y;
  re(i, 3){
    std::cin >> x >> y;
    a[x]++, a[y]++;
  }
  ll r = 0, l = 100000;
  rep(i, 1, 5){
    r = max(r, a[i]);
    l = min(l, a[i]);
  }
  if(r==2&&l==1) std::cout << "YES" << '\n';
  else std::cout << "NO" << '\n';
}
