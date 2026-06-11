#include<iostream>
using namespace std;
typedef long long ll;
#define fr(i,n) for(int i=0;i<n;i++)

int main(){
  ll n,c,x[100010],v[100010],x0[100010],v0[100010],ans=0,x1[10][100010],v1[10][100010],a[10]={},hara[100010];
  cin>>n>>c;
  fr(i,n){cin>>x[i]>>v[i];x0[n-1-i]=c-x[i];v0[n-1-i]=v[i];}
  hara[0]=v[0]-x[0];
  fr(i,n-1){
    hara[i+1]=hara[i]+v[i+1]+x[i]-x[i+1];
  }
  fr(i,n){
    if(a[0]<hara[i]) a[0]=hara[i];
    v1[0][i]=a[0];
  }
  fr(i,n){
    if(a[1]<hara[i]-x[i]) a[1]=hara[i]-x[i];
    v1[1][i]=a[1];
  }
  
  
  
  hara[0]=v0[0]-x0[0];
  fr(i,n-1){
    hara[i+1]=hara[i]+v0[i+1]+x0[i]-x0[i+1];
  }
  fr(i,n){
    if(a[2]<hara[i]) a[2]=hara[i];
    v1[2][n-1-i]=a[2];
  }
  fr(i,n){
    if(a[3]<hara[i]-x0[i]) a[3]=hara[i]-x0[i];
    v1[3][n-1-i]=a[3];
  }
  ans=max(max(ans,v1[0][n-1]),v1[2][0]);
  fr(i,n-1){
    ans=max(ans,v1[0][i]+v1[3][i+1]);
    ans=max(ans,v1[1][i]+v1[2][i+1]);
  }
  cout<<ans;
}