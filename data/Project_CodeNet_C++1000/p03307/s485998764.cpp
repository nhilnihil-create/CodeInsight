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
  ll n;cin>>n;
  if(n%2==0){
    cout<<n<<endl;
  }
  else{cout<<2*n<<endl;}
}