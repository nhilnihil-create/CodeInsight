#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef vector<pair<ll,ll> > vp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
const int INF=1e9+7;

int main(){
  ll n,ans1=0,ans2=0,ans;cin>>n;
  vll a(n);
  rep(i,0,n){
    cin>>a[i];
    a[i]-=(i+1);
  }
  sort(a.begin(),a.end());
  ll c;
  c=a[(n/2)];
  rep(i,0,n){
    ans1+=abs(a[i]-c);
  }
  cout<<ans1<<endl;
}