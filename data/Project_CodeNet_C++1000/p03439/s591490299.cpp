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
  ll n;std::cin >> n;
  std::cout << 0 << endl <<  std::flush;
  string s;std::cin >> s;
  if(s=="Vacant") return 0;
  ll l = 0, r = n;
  while(r-l>1){
    ll mid = (l+r)/2;
    std::cout << mid << endl << std::flush;
    string t;std::cin >> t;
    if(t=="Vacant") return 0;
    if((mid%2!=0)^(t==s))l = mid;
    else r = mid;
  }
  std::cout << r << endl << std::flush ;
  return 0;
}
