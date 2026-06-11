#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n,a,b;cin>>n>>a>>b;
  if(a+b>n+1||a*b<n){
    cout<<-1<<endl;
    return 0;
  }
  vector<ll> ans;
  for(ll i=b;i>=1;i--){
    ans.push_back(i);
  }
  ll nb=n-b;
  ll na=a-1;
  ll now=b;
  for(;;){
    if(na==0)break;
    ll g=ceil((double)nb/na);
    for(ll i=now+g;i>now;i--){
      ans.push_back(i);
    }
    now+=g;
    nb-=g;
    na--;
  }
  for(ll i=0;i<n;i++)cout<<ans[i]<<" ";
}