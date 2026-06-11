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
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define SIZE(a) int((a).size())

int main(){
  int n;cin>>n;double ans=0;
  rep(i,0,n){
    double x;string u;
    cin>>x>>u;
    if(u=="JPY"){ans+=x;}
    else{ans+=x*380000;}
  }
  cout<<ans<<endl;
}