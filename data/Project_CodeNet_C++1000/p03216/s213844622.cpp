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
#define rep(a, b, c) for(ll c=a;c<b;c++)
#define re(b, c) for(ll c=0;c<b;c++)
typedef long long int ll;
typedef long double ld;
using namespace std;

int main(int argc, char const *argv[]) {
  ll n, q;
  string s;
  std::cin >> n; std::cin >> s; std::cin >> q;
  re(q,i){
    ll t, ans=0, a=0, b=0, c=0;std::cin >> t;
    re(t, j){
      if(s[j]=='D') a++;
      if(s[j]=='M') b+=a, c++;
      if(s[j]=='C') ans+=b;
    }
    //std::cout << ans << '\n';
    rep(t, n, j){
      if(s[j-t]=='D') a--, b-=c;
      if(s[j-t]=='M') c--;
      if(s[j]=='D') a++;
      if(s[j]=='M') b+=a, c++;
      if(s[j]=='C') ans+=b;
    }
    std::cout << ans << '\n';
  }
  return 0;
}
