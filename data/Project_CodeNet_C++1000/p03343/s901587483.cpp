#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int main(){
  ll n,k,q;
  cin>>n>>k>>q;
  vector<ll> ar;
  vector<ll> vec;
  for(int i=0;i<n;i++){
    ll a;
    cin>>a;
    ar.push_back(a);
    vec.push_back(a);
  }
  ar.push_back(0);
  sort(vec.begin(),vec.end());
  vec.erase(unique(vec.begin(),vec.end()),vec.end());
  ll border=0,ans=174417441744;
  for(int b=0;b<vec.size();b++){
    vector<ll> kans;
    priority_queue<ll,vector<ll>,greater<ll>> pque;
    for(int i=0;i<=n;i++){
      if(ar[i]>border) pque.push(ar[i]);
      else{
        ll sz=max((ll)pque.size()-k+1,(ll)0);
        for(int j=0;j<sz;j++){
          kans.push_back(pque.top());
          pque.pop();
        }
        while(!pque.empty()) pque.pop();
      }
    }
    sort(kans.begin(),kans.end());
    if(kans.size()<q) break;
    else ans=min(ans,kans[q-1]-kans[0]);
    border=vec[b];
  }
  cout<<ans<<endl;
}
