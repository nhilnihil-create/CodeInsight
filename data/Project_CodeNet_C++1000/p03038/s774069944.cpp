#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  ll vec[n];
  vector<pair<ll,int>> vecb(m);
  for(int i=0;i<n;i++){
    cin>>vec[i];
  }
  sort(vec,vec+n);
  for(int i=0;i<m;i++){
    ll a,b;
    cin>>a>>b;
    vecb[i]=make_pair(b,a);
  }
  sort(vecb.begin(),vecb.end());
  reverse(vecb.begin(),vecb.end());
  ll vecc[n]={};
  int now=0,next;
  for(int i=0;i<m;i++){
    next=min(now+vecb[i].second,n);
    for(int j=now;j<next;j++){
      vecc[j]=vecb[i].first;
    }
    now=next;
  }
  ll ans=0;
  for(int i=0;i<n;i++){
    ans+=max(vec[i],vecc[i]);
  }
  cout<<ans<<endl;
}