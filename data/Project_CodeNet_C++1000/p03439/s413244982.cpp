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
#define rrepi(i,a,b) for(ll i=(ll)(b-1);i>=(ll)(a);i--)

#define all(x) (x).begin(),(x).end()

template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;

using namespace std;


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;
  cin>>n;
  cout<<0<<endl;
  string s;
  cin>>s;
  ll l=0,r=0;
  if(s=="Female")l=1;
  if(s=="Vacant"){
    return 0;
  }

  cout<<n-1<<endl;
  cin>>s;
  if(s=="Female")r=1;
  if(s=="Vacant")return 0;
  ll li=0,ri=n-1;
  while(ri-li>1){
    ll mid=(li+ri)/2;
    cout<<mid<<endl;;
    cin>>s;
    ll f=0;
    if(s=="Vacant")return 0;
    if(s=="Female")f=1;
    if(mid%2)f^=1;
    if(f==l)li=mid;
    else ri=mid;
  }

  return 0;

}
