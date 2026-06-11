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
  vll d(n);
  re(n, i) std::cin >> d[i];
  if(n>=24){
    std::cout << 0 << '\n';
    return 0;
  }
  int ans = 0;

  for(int i=0;i<(1<<n);i++){
    vector<short> v(24, 0);
    int tmp = 24;
    v[0]++;
    for(int j=0;j<n;j++){
      if((i&(1<<j))!=0||d[j]==0) {
        if(v[d[j]]==1){
          tmp = 0;
          break;
        }
        v[d[j]]++;
      }else {
        if(v[24-d[j]]==1){
          tmp = 0;
          break;
        }
        v[24 - d[j]]++;
      }
    }
    int m = 0;
    for(int j=1;j<24;j++){
      if(v[j]==1){
        tmp = min(tmp, j-m);
        m = j;
      }
    }
    tmp = min(tmp, 24-m);
    ans = max(ans, tmp);
    //std::cout << tmp << '\n';
  }
  std::cout << ans << '\n';
  return 0;
}
