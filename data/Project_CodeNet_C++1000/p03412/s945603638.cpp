#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n;cin>>n;
  ll a[n],b[n];
  for(ll i=0;i<n;i++)cin>>a[i];
  for(ll i=0;i<n;i++)cin>>b[i];
  ll ans[30];
  for(ll i=0;i<=29;i++){
    ll now=pow(2,i+1);
    vector<ll> va(n),vb(n);
    for(ll j=0;j<n;j++){
      va[j]=a[j]%now;
      vb[j]=b[j]%now;
    }
    sort(va.begin(),va.end());
    sort(vb.begin(),vb.end());
    ll cnt=0;
    for(ll j=0;j<n;j++){
      ll g=va[j];
      if(g<=now/2){
        ll s=lower_bound(vb.begin(),vb.end(),now/2-g)-vb.begin();
        ll t=lower_bound(vb.begin(),vb.end(),now-g)-vb.begin();
        cnt+=t-s;
      }
      else{
        ll s=lower_bound(vb.begin(),vb.end(),now-g)-vb.begin();
        ll t=lower_bound(vb.begin(),vb.end(),now-(g-now/2))-vb.begin();
        cnt+=s+vb.size()-t;
      }
    }
    ans[i]=cnt%2;
  }
  ll sum=0;
  for(ll i=0;i<30;i++)sum+=pow(2,i)*ans[i];
  cout<<sum<<endl;
}