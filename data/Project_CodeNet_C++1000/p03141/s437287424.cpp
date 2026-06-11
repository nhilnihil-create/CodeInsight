#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <queue>
#include <map>
#include <numeric>
#include <unordered_map>
#include <iomanip>
#include <functional>
#include <bitset>
#include <complex>
#include <stack>
#include <cstdint>



#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rrep(i, n) for(ll i = (ll)(n-1); i >= 0; i--)
#define repi(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rrepi(i,a,b) for(ll i=(ll)(b);i>=(ll)(a);i--)

#define all(x) (x).begin(),(x).end()

template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;

using namespace std;


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;cin>>n;
  struct ab{ll a,b;};
  vector<ab>dish(n);
  rep(i,n)cin>>dish[i].a>>dish[i].b;
  sort(all(dish),[](ab x,ab y){return x.a+x.b>y.a+y.b;});
  ll res=0;
  rep(i,n){
    if(i%2==0)res+=dish[i].a;
    else res-=dish[i].b;
  }
  cout<<res<<endl;

  return 0;

}
