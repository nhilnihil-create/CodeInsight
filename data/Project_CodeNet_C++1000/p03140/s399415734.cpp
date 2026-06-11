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
  ll n;std::cin >> n;
  string a, b, c;
  std::cin >> a >> b >> c;
  vector<set<ll>> t(n);
  re(i, n){
    t[i].insert(a[i]);
    t[i].insert(b[i]);
    t[i].insert(c[i]);
  }
  ll ans = 0;
  re(i, n){
    if(t[i].size()==2) ans++;
    else if(t[i].size()==3) ans +=2;
  }
  std::cout << ans << '\n';
}
