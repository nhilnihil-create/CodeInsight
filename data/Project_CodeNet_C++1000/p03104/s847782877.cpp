#include<iostream>
using namespace std;
#define ll long long

ll A,B;

ll f(ll N){
  if(N&1){
    if(((N+1)/2)&1) return 1;
    else return 0;
  }else{
    if((N/2)&1) return N^1;
    else return N;
  }
}

int main(){
  cin>>A>>B;
  if(A==0) cout<<f(B)<<endl;
  else cout<<(ll)(f(B)^f(A-1))<<endl;
  return 0;
}