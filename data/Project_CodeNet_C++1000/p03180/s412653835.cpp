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
//typedef __int128_t lll;
using namespace std;

vll p(1<<16, 0);
vll ans(1<<16, -1);

ll f(ll num){
  if(num==0) return 0;
  if(ans[num]!=-1) return ans[num];

  //std::cout << num << '\n';

  ll ret = p[num];
  int sub = num;
  do{
    if(num!=sub&&sub!=0) ret = max(ret, f(sub) + f(num - sub));
    sub = (sub - 1) & num;
  }while(sub != num);

  return ans[num] = ret;
}
int main(int argc, char const *argv[]) {
  ll n;std::cin >> n;
  vvl a = vv(n, n, 0, ll);
  re(i, n) re(j, n) scanf("%lld", &a[i][j]);
  for(int i=0;i<(1<<n);i++){
    ll num = 0;
    for(int j=0;j<n;j++){
      for(int k=0;k<n;k++){
        if(!(i>>j&1)||!(i>>k&1)) continue;
        num += a[j][k];
      }
    }
    p[i] = num;
  }
  for(int i=0;i<n;i++) ans[1<<i] = 0;
  std::cout << f((1<<n)-1)/2 << '\n';
  return 0;
}
