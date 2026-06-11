#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int n,k,q;
vector<ll> v;

ll solve(ll x){

  vector<ll> t;
  for(int i=0;i<v.size();i++){
    if(v[i]>=x){
      vector<ll> w;
      for(;i<v.size()&&v[i]>=x;i++){
        w.push_back(v[i]);
      }
      if(w.size()>=k){
        sort(w.begin(),w.end());
        for(int j=0;j+k-1<w.size();j++){
          t.push_back(w[j]);
        }
      }
    }
  }

  if(t.size()<q) return -1;
  else{
    sort(t.begin(),t.end());
    return t[q-1];
  }
}

int main(){
  cin>>n>>k>>q;
  for(int i=0;i<n;i++){
    ll a;
    cin>>a;
    v.push_back(a);
  }

  ll ans=1e9;
  for(int i=0;i<n;i++){
    ll z=solve(v[i]);
    if(z==-1) continue;
    ans=min(ans,z-v[i]);
  }

  cout<<ans<<endl;


  return 0;
}
