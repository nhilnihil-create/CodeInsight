#include <bits/stdc++.h>
 
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
const ll inf=1e9;
const int MAX = 510000;
const ll MOD = 998244353;
vll divide(ll n){
    vll res;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            res.push_back(i);
            if(i!=n/i){
                res.push_back(n/i);
            }
        }
    }
    sort(res.begin(),res.end());
    return res;
}
int main(){
  ll n;cin>>n;
  ll ans=0;
  for(ll i=1;i*i<=n;i++){
    if(n%i==0&&i<(n/i)-1){
       ans+=(n/i)-1;
    }
  }
  cout<<ans<<endl;
}

