#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
void out(vector<ll> v,ll n){
  vector<ll> cmp;
  for(int i=0;i<n;i++) cmp.push_back(v[i]);
  sort(cmp.begin(),cmp.end());
  for(int i=n-1;i>=0;i--){
    int pos=lower_bound(cmp.begin(),cmp.end(),v[i])-cmp.begin();
    cout<<pos+1<<" ";
  }
  cout<<endl;
}
signed main(){
  ll n,a,b;
  cin>>n>>a>>b;
  if(a*b<n||a+b-1>n){
    cout<<-1<<endl;
    return 0;
  }
  ll fn=n;
  n=a*b;
  ll dec=n-fn;
  vector<ll> ans;
  for(int i=a;i>0;i--){
    ans.push_back(i);
    if(i==1){
      for(int j=1;j<b;j++) ans.push_back(j*a+i);
    }
    else{
      ll mns=min(dec,b-1);
      dec-=mns;
      ll kb=b-mns;
      for(int j=1;j<kb;j++) ans.push_back(j*a+i);
    }
  }

  out(ans,fn);
}
