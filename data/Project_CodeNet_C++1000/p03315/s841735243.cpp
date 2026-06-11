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
const int MOD = 1000000007;
const int MAX = 510000;

int main(){
  int ans=0;
  rep(i,0,4){
    char x;cin>>x;
    if(x=='+'){ans++;}
    else{ans--;}
  }
  cout<<ans<<endl;
}

