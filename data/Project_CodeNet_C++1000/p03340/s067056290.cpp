//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using st=string;
using ch=char;
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<P> vP;
typedef vector<ch> vc;
typedef vector<vc> vvc;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
#define ROF(i,a,b) for(ll i=a;i>=b;i--)
#define per(i,a) ROF(i,a,0)
#define pb push_back
const ll MOD=1000000007;
const ll MOD2=998244353;
const ld PI=acos(-1);
const ll INF=1e18;
st abc="abcdefghijklmnopqrstuvwxyz";
st ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
struct edge{ll to,cost;};

int main() {
  ll n;
  cin >> n;
  vl a(n);
  rep(i,n){
    cin >> a[i];
  }
  ll r=0;
  ll sum=a[0],xorsum=a[0];
  ll ans=0;
  rep(i,n){
    while(sum==xorsum&&r<n-1){
      r++;
      sum+=a[r];
      xorsum^=a[r];
    }
    if(r==n-1){
      if(sum!=xorsum){
        sum-=a[r];
        xorsum^=a[r];
        r--;
      }
    }
    else{
      sum-=a[r];
      xorsum^=a[r];
      r--;
    }
    ans+=r-i+1;
    sum-=a[i];
    xorsum^=a[i];
  }
  cout << ans << endl;
}