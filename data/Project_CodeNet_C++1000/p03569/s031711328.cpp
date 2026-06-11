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
  string ss,s;
  cin>>ss;
  n=ss.length();
  vector<ll>cnt;
  ll x=0;
  rep(i,n){
    if(ss[i]!='x'){
      cnt.push_back(x);
      s.push_back(ss[i]);
      x=0;
    }
    else {
      x++;
    }
  }
  cnt.push_back(x);
  auto t=s;
  auto rc=cnt;
  reverse(all(t));
  reverse(all(rc));
  ll f=1;
  ll res=0;
  rep(i,s.size()){
    if(s[i]!=t[i])f=0;
  }
  rep(i,cnt.size()){
    res+=max(cnt[i],rc[i])*2-cnt[i]-rc[i];
  }
  if(!f)res=-2;
  cout<<res/2<<endl;
  return 0;

}
