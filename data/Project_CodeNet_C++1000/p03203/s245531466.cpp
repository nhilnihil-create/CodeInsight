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

int main(){
  int h,w,n;
  cin>>h>>w>>n;
  vector<pair<ll,ll>> v;
  ll g[h+1]={};
  for(int i=0;i<=h;i++) g[i]=w+1;
  map<pair<ll,ll>,int> mp;
  for(int i=0;i<n;i++){
    ll x,y;
    cin>>x>>y;
    v.push_back(make_pair(x,y));
    g[x]=min(g[x],y);
  }

  ll ans=h-1;
  ll pre=1;
  for(int i=2;i<=h;i++){
    //cout<<i<<" "<<pre<<" "<<ans<<endl;
    if(g[i]<=i-1){
      if(g[i]<=pre){
        //cout<<i<<" "<<g[i]<<" "<<ans<<endl;
        ans=min(ans,(ll)i-2);
      }
      pre=min(pre+1,g[i]-1);
    }else{
      if(pre+1<g[i]) pre=pre+1;
    }
  }

  cout<<ans+1<<endl;

  return 0;
}
