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
ll roundd(ll x,ll n){
  if(x>n){return x%n;}
  else if(x<0){return x%n+n;}
  else return x;
}
ll gcd(ll a,ll b){
   if (a%b == 0){
        return(b);
    }
    
   else{
       return(gcd(b, a%b));
    }
}
int main(){
  ll n;cin>>n;
  vll s(n);
  rep(i,0,n){
    cin>>s[i];
  }
  ll ans=0;
  vll l(n),r(n);
  l[0]=s[0];r[n-1]=s[n-1];
  rep(i,0,n-1){
    l[i+1]=gcd(l[i],s[i+1]);
    
  }
  drep(i,n-2,0){
    r[i]=gcd(r[i+1],s[i]);
  }
  ans=max(r[1],l[n-2]);
  rep(i,1,n-1){
    ans=max(ans,gcd(l[i-1],r[i+1]));
  }

  cout<<ans<<endl;
  
}

