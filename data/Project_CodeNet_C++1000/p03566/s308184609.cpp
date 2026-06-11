#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll N; cin>>N;
  ll T[N],V[N],a=0,A[N];
  for(int i=0; i<N; i++){ll t; cin>>t; t*=2; T[i]=t; a+=t, A[i]=a;}
  for(int i=0; i<N; i++){ll v; cin>>v; v*=2; V[i]=v;}
  ll s=0, t=0, Z[a+1]; Z[0]=0, Z[a]=0;
  for(int i=1,j=0; i<a; i++){
    Z[i]=V[j];
    if(i==A[j]){
      j++;
      Z[i]=min(Z[i],V[j]);
    }
  }
  for(int i=1; i<=a; i++){
    Z[i]=min(Z[i],Z[i-1]+1);}
  for(int i=a-1; i>=0; i--){
    Z[i]=min(Z[i],Z[i+1]+1);
  }
//  for(int i=139; i<=a; i++){cout<<"i:"<<i<<" Z:"<<Z[i]<<endl;}
  double ans=0;
  for(int i=0; i<a; i++){
    ans+=Z[i];
    if(Z[i]<Z[i+1]) ans+=0.5;
    else if(Z[i]>Z[i+1]) ans-=0.5;
  }
  cout<<fixed<<setprecision(10)<<ans/4<<endl;
}