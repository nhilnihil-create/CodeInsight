#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define SIZE(a) int((a).size();
const int INF=INT_MAX;
int main(){
  ll n,k;cin>>n>>k;
  ll d=n/k,ans=d*d*d;
  if(k%2==0){
    if(n%k>=k/2){d++;}
    ans+=d*d*d;
  }
  cout<<ans<<endl;
}