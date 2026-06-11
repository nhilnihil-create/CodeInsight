#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
ll n;
vector<ll> vec;
bool judge(ll x){
  map<ll,ll> mp;
  for(int i=1;i<n;i++){
    if(vec[i-1]>=vec[i]){
      if(mp.find(vec[i])==mp.end()) mp[vec[i]]=1;
      else mp[vec[i]]++;
      auto itr=mp.lower_bound(vec[i]);
      itr++;
      mp.erase(itr,mp.end());
      ll pos=vec[i];
      while(1){
        if(mp[pos]>=x){
          if(pos<=1){
            return false;
          }
          mp.erase(pos);
          if(mp.find(pos-1)==mp.end()) mp[pos-1]=1;
          else mp[pos-1]++;
          pos--;
        }
        else break;
      }
    }
  /*  if(x==2){
      cout<<i<<": ";
    for(auto itr=mp.begin();itr!=mp.end();itr++){
      cout<<(itr->first)<<" "<<(itr->second)<<" /// ";
    }
    cout<<endl;
  }*/
  }
  return true;
}
signed main(){
  cin>>n;
  ll past=0;
  bool f=true;
  for(int i=0;i<n;i++){
    ll a;
    cin>>a;
    if(a<=past) f=false;
    past=a;
    vec.push_back(a);
  }
  if(f) {
    cout<<1<<endl;
    return 0;
  }
  ll lb=1,rb=1000000007;
  while(rb-lb>1){
    ll mid=(lb+rb)/2;
    if(judge(mid)) rb=mid;
    else lb=mid;
//    cout<<"M:"<<mid<<endl;
  }
  cout<<rb<<endl;
}
