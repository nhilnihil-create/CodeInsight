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

//-------------------------------------------------------------------
struct segtree{
  ll M=1;
  vector<ll> dat;
  segtree(ll N, ll num){
    while(M<N) M*=2;
    for(int i=0;i<M*2-1;i++)  dat.push_back(num);
  }
  void update(int x, int k, int l=0, int r=-1){
    if(r==-1) r = M;
    k+=M-1;
    dat[k] += x;
    while(k>0) k = (k-1)/2, dat[k] += x;
  }
  ll query(int a, int b=-1, int k=0, int l=0, int r=-1){
    if(r==-1) r = M;
    if(b==-1) b = M;
    if(r<=a || b<=l) return 0;
    if(a<=l && r<=b) return dat[k];
    ll A = query(a, b, k*2+1, l, (l+r)/2);
    ll B = query(a, b, k*2+2, (l+r)/2, r);
    return A + B;
  }
};
//-------------------------------------------------------------------
int main(int argc, char const *argv[]) {
  ll a, n, k;std::cin >> n >> k;
  segtree seg(n, 0);
  re(i, n){
    std::cin >> a;
    seg.update(a, i);
  }
  vll c;
  for(int l=0;l<n;l++) for(int r=l+1;r<=n;r++) c.push_back(seg.query(l, r));
  sort(c.begin(), c.end());
  reverse(c.begin(), c.end());
  ll ans = 0;
  vll r(64, 1);rep(i, 1, 64) r[i] = r[i-1]*2;
  for(ll i=50;i>=0;i--){
    ll C = 0;
    vll t;
    re(j, c.size()) if(r[i]&c[j]) C++, t.push_back(c[j]);
    if(C<k) continue;
    //std::cout << i << '\n';
    c = t, ans += r[i];
  }
  std::cout << ans << '\n';
  return 0;
}
