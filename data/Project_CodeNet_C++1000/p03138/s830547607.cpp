#include "bits/stdc++.h"
 
using namespace std;
typedef int64_t ll;
typedef vector<int64_t> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef pair<ll,ll> P;
typedef vector<P> vp;
typedef vector<double> vd;
typedef vector<vd> vvd;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define SIZE(a) int((a).size())
int num[3][3];
int main(){
  ll n,k,ans=0;bool ok=true;
  cin>>n>>k;
  
  vll a(n), b(40);
  
  REP(i,n){
    cin>>a[i];
    bitset<40> bit(a[i]);
    REP(j,40){
      if(bit.test(j)){b[j]++;}
    }
  }
  REP(j,40){
    if((k>>j)&1){ans+=(1LL<<j)*(n-b[j]);}
    else{ans+=(1LL<<j)*b[j];}
  }
  bitset<40> K(k);
  REP(i,40){
    ll f=0;
    if(!((k>>i)&1)){continue;}
    REP(j,i){
      f+=(1LL<<j)*max(b[j],n-b[j]);
    }
    f+=(1LL<<i)*b[i];
    FOR(j,i+1,40){
      if((k>>j)&1){f+=(1LL<<j)*(n-b[j]);}
      else{f+=(1LL<<j)*b[j];}
    }
    ans=max(ans,f);
  }
  
  cout<<ans<<endl;
}