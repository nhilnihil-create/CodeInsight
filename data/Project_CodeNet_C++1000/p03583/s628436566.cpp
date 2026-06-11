#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll N,h,n,w;
int main(){
  cin>>N;
  for(ll i=1;i<=3500;i++)
    for(ll j=1;j<=3500;j++)
      if(N*(i+j)<(4*i*j) && (N*i*j)%(4*i*j-N*(i+j))==0){
      h=i;n=j;w=(N*i*j)/(4*i*j-N*(i+j));
      }cout<<h<<" "<<n<<" "<<w<<endl;
  return 0;
}