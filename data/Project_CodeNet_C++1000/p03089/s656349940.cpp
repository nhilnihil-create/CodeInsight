#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef pair<ll,ll> P;
typedef vector<P> vp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define drep(i,a,b) for(ll i=(a);i>=(b);--i)
#define SIZE(a) ll((a).size())
#define out(a) cout<<(a)<<endl;
const int inf=INT_MAX;
const int MAX = 510000;
const ll MOD = 1000000007;

int main(){
  ll n;cin>>n;
  vll b(n);
  rep(i,0,n){
    cin>>b[i];
  }
  rep(i,0,n){
    if(i+1<b[i]){
      cout<<-1<<endl;return 0;
    }
  }
  vll c(0);
  rep(j,0,n){
    drep(i,b.size()-1,0){
      if(b[i]==i+1){
        c.push_back(b[i]);
        b.erase(b.begin()+i);
        break;
      }
    }
    if(b.size()==0)break;
  }
  reverse(c.begin(),c.end());
  rep(i,0,n){
    cout<<c[i]<<endl;
  }
}


