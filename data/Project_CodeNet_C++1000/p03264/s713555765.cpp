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
  ll k,ans;cin>>k;
  ll x=k/2;
  if(k%2==0){
    ans=x*x;
  }
  else{
    ans=x*(k-x);
  }
  cout<<ans<<endl;
}