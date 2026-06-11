#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n;
  cin>>n;
  ll a[n],b[n];
  ll suma=0,sumb=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
    suma+=a[i];
  }
  for(int i=0;i<n;i++){
    cin>>b[i];
    sumb+=b[i];
  }
  if(suma>sumb){
    cout<<"No"<<endl;
    return 0;
  }
  ll x=0,y=0;
  for(int i=0;i<n;i++){
    if(a[i]>b[i]){
      y+=a[i]-b[i];
    }
    if(a[i]<b[i]){
      x+=(b[i]-a[i])/2;
    }
  }
  if(x<y){
    cout<<"No"<<endl;
    return 0;
  }
  cout<<"Yes"<<endl;
}