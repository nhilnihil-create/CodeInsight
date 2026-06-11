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
#define vll vector<ld>
#define rep(c, a, b) for(ll c=a;c<b;c++)
#define re(c, b) for(ll c=0;c<b;c++)
typedef long long int ll;
typedef long double ld;
using namespace std;
#include <iomanip>

int main(int argc, char const *argv[]) {
  ld n;std::cin >> n;
  vll t(n), v(n+1, 0), u(40002, 0);
  re(i, n) {
    std::cin >> t[i];
    if(i>=1) t[i] += t[i-1];
  }
  re(i, n) std::cin >> v[i];
  ld ans = 0;
  re(i, n){
    for(ld j=(i==0?0:t[i-1])+0.5;j<=t[i];j+=0.5){
      for(ld k=-0.5;k<=0.5;k+=0.5){
        ld tmp = u[j*2-1]+k;
        bool e = true;
        for(ld l=i+1;l<=n;l++) {
          //if(j==70.5) std::cout << (tmp-v[l]) << " " << (t[l-1]-j) << '\n';
          if((tmp-v[l])>(t[l-1]-j)) e = false;
        }
        if(tmp<=v[i]&&e) u[j*2] = tmp;
      }
      //if(j==70.5) std::cout << u[j*2-1] << " " << u[j*2] << '\n';
      if(u[j*2]==u[j*2-1]) ans += u[j*2]/2;
      else if(u[j*2]==u[j*2-1]-0.5) ans+=(u[j*2]/2)+0.125;
      else ans+=(u[j*2-1]/2)+0.125;
      //std::cout << "now" <<j << " " << ans << '\n';
    }
  }
  std::cout << fixed << setprecision(20) << ans << '\n';
  return 0;
}
