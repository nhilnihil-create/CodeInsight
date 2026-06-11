#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  ll N;
  cin>>N;
  for(ll h=1;h<=3500;h++){
    for(ll n=1;n<=3500;n++){
      if(4*h*n-N*n-N*h>0){
        if((N*h*n)%(4*h*n-N*n-N*h)==0){
          cout<<h<<" "<<n<<" "<<(N*h*n)/(4*h*n-N*n-N*h)<<endl;
          return 0;
        }
      }
    }
  }
}