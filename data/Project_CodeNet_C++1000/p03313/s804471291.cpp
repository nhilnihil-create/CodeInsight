#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n;cin>>n;
  ll u=pow(2,n);
  ll a[u];
  for(ll i=0;i<u;i++)cin>>a[i];
  ll mm[u][2];
  for(ll i=0;i<u;i++){
    mm[i][0]=a[0];
    mm[i][1]=0;
  }
  ll ma=0;
  for(ll i=1;i<u;i++){
    if(a[i]>=mm[i][0]){
      mm[i][1]=mm[i][0];
      mm[i][0]=a[i];
    }
    else if(a[i]>=mm[i][1])mm[i][1]=a[i];
    ma=max(ma,mm[i][0]+mm[i][1]);
    cout<<ma<<endl;
    ll b=i;
    b=i|(b+1);
    while(b<u){
      if(a[i]>=mm[b][0]){
        mm[b][1]=mm[b][0];
        mm[b][0]=a[i];
      }
      else if(a[i]>=mm[b][1])mm[b][1]=a[i];
      b=i|(b+1);
    }
    //cout<<mm[5][0]<<" "<<mm[6][1]<<endl;
  }
  for(ll i=0;i<u;i++){
    //cout<<mm[i][0]<<" "<<mm[i][1]<<endl;
  }
}