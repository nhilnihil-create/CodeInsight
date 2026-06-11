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
typedef __int128_t lll;
using namespace std;

int main(int argc, char const *argv[]) {
  ll n;std::cin >> n;

  vll ni, san, roku;

  for(int i=2;i<=30000;i++){
    if(i%6==0) roku.push_back(i);
    else if(i%3==0) san.push_back(i);
    else if(i%2==0) ni.push_back(i);
  }

  if(n==3){
    std::cout << "2 5 63" << '\n';
  }else if(n>=4){
    vll ans;
    ll f = min((ll)ni.size(), n-2);
    if(f%2) f--;
    ll s = min(n-f, (ll)san.size());
    if(s%2) s--;
    re(i, f) ans.push_back(ni[i]);
    re(i, s) ans.push_back(san[i]);
    re(i, n-f-s) ans.push_back(roku[i]);
    re(i, ans.size()) std::cout << ans[i] << (i==ans.size()-1?"\n":" ");
  }
  return 0;
}
