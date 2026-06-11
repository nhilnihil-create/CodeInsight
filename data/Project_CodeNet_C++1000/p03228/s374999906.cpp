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
  ll a, b, k;std::cin >> a >> b >> k;
  re(i, k){
    if(i%2==0){
      if(a%2==1) a--;
      b += a/2;
      a/=2;
    }else{
      if(b%2==1) b--;
      a += b/2;
      b/=2;
    }
  }
  std::cout << a << " " << b << '\n';
}
