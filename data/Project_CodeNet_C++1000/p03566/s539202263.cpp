#include<iostream>
using namespace std;
typedef long long int ll;
typedef long double ld;
int main(){
  ll n,t[110],v[110],ts[110]={};
  ld a[50000]={},ans=0;
  cin>>n;
  ts[0]=0;
  for(int i=0;i<n;i++){cin>>t[i];ts[i+1]=ts[i]+t[i];}
  for(int i=0;i<n;i++) cin>>v[i];
  for(ll i=0;i<=2*ts[n];i++){
    a[i]=  min((ld)i/2,(ld)ts[n]-(ld)i/2);
    for(int j=0;j<n;j++){
      if(i < 2*ts[j]) a[i]=  min(a[i],(ld)v[j]+(ld)ts[j]-(ld)i/2);
      else if( i > 2*ts[j+1]) a[i]= min(a[i],(ld) v[j]+(ld)i/2-(ld)ts[j+1]);
      else a[i]=min(a[i],(ld) v[j]);
    }
  }
  for(int i=0;i<2*ts[n];i++){
    ans+=(a[i]+a[i+1])/4;
  }
  printf("%f",(double)ans);
}