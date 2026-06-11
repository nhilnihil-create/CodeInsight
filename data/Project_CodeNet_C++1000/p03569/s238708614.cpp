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
  string s;std::cin >> s;ll n = s.size();
  string t = "";
  re(i, n) if(s[i]!='x') t+=s[i];
  for(int i=0;i<t.size()/2;i++){
    if(t[i]!=t[t.size()-1-i]){
      std::cout << -1 << '\n';
      return 0;
    }
  }
  vll spot(t.size()+1, 0);
  ll now = 0;
  for(int i=0;i<n;i++){
    if(s[i]=='x') spot[now]++;
    else now++;
  }
  ll ans = 0;
  re(i, (t.size()+1)/2){
    ans += max(spot[i], spot[t.size()-i]) - min(spot[i], spot[t.size()-i]);
  }
  std::cout << ans << '\n';
  return 0;
}
