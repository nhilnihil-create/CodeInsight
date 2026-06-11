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
#define vvc vector<vector<char>>
#define vll vector<ll>
#define rep(a, b, c) for(ll c=a;c<b;c++)
#define re(b, c) for(ll c=0;c<b;c++)
typedef long long int ll;
typedef long double ld;
using namespace std;

int main(int argc, char const *argv[]) {
  ll n, q;std::cin >> n >> q;
  string s;std::cin >> s;
  vvc t = vv(q, 2, 0, char);
  for(int i=0;i<q;i++) std::cin >> t[i][0] >> t[i][1];
  ll l = -1, r = n;
  while(r-l>1){
    ll mid = (l+r)/2;
    ll now = mid;
    re(q, i) if(now>=0&&now<n&&s[now]==t[i][0]) now = now + (t[i][1]=='L'?-1:1);
    if(now<0) l = mid;
    else r = mid;
  }
  ll ok_right = r;
  l = -1, r = n;
  while(r-l>1){
    ll mid = (l+r)/2;
    ll now = mid;
    re(q, i) if(now>=0&&now<n&&s[now]==t[i][0]) now = now + (t[i][1]=='L'?-1:1);
    if(now>=n) r = mid;
    else l = mid;
  }
  if(ok_right==n||l==-1){
    std::cout << 0 << '\n';
    return 0;
  }
  //std::cout << l << " " << ok_right << '\n';
  std::cout << max(l - ok_right + 1, (ll)0) << '\n';
  return 0;
}
