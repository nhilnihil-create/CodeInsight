
#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <cmath>
#include <string>
#include <sstream>
#include <queue> 
#include <list>
#include <stack>
#include <unordered_map>
#include <algorithm> 
#include <numeric>  
#include <functional>
#include <cassert>
#include <bitset>
#include <cctype>  
#include <iomanip> 
#include <limits>  
#include <regex>

#define rep(i, n) for(int i = 0; i < (int)(n);    i++)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;

ll gcd ( ll a, ll b ) { if ( b == 0 ) return a; else return gcd ( b, a%b ); }
ll lcm ( ll a, ll b ) { return a * b / gcd(a, b); }

int main (void) {
  std::cin.tie(0);  std::ios::sync_with_stdio(false);
  int N; std::cin >> N;
  std::vector<double> t(N); rep(i,N) std::cin >> t[i];
  std::vector<double> v(N); rep(i,N) std::cin >> v[i];

  double ret = 0, sp = 0;
  rep(i,N) {
    for(double j=0; j<t[i]; j+=0.5) {
      bool flag1 = true, flag2 = true;
      double ti = t[i]-j-0.5;
      for(int k=i+1; k<N; k++) {
        ti += t[k];
        if(sp+0.5-ti > v[k+1]) flag1 = false;
        if(sp-v[k+1] > ti) flag2 = false;
      }
      if(sp+0.5 <= v[i] && flag1 && (sp+0.5-(t[i]-j-0.5)) <= v[i+1]) {
        ret += sp*0.5;
        ret += 0.125;
        sp += 0.5;
      } else if(sp - v[i+1] <= t[i]-j-0.5 && flag2) {
        ret += sp*0.5;
      } else {
        sp -= 0.5;
        ret += sp*0.5;
        ret += 0.125;
      }
    }
  }
  std::cout << std::fixed << std::setprecision(12) << ret << std::endl;
  return 0;
}
