#include<iostream>
#include<algorithm>
using namespace std;
using ll=long long;
int main(){

  ll N;
  cin>>N;
  for(ll i=1;i<=3500;i++){
    
    if(4*i<=N){
    
      continue;
    }
    for(ll j=i;j<=3500;j++){
    
      if(4*i*j<=(i+j)*N){
        
        continue;
      }
      for(ll k=j;k<=3500;k++){
      
        if(4*i*j*k==N*(i*j+j*k+k*i)){
        
          cout<<i<<" "<<j<<" "<<k<<endl;
          return 0;
        }
      }
    }
  }
  return 0;
}