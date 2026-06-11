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
  ll n;cin>>n;
  vector<ll>a(n),b(n);
  rep(i,n){
    cin>>a[i];
  }
  rep(i,n)cin>>b[i];
  ll cnt=0;
  rep(i,n){
    cnt+=(max(0ll,b[i]-a[i])+1)/2;
    a[i]+=(max(0ll,b[i]-a[i])+1)/2*2;
  }
  rep(i,n){
    //cout<<b[i]<<" "<<a[i]<<endl;
    cnt-=a[i]-b[i];
  }
  if(cnt>=0)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;

}
