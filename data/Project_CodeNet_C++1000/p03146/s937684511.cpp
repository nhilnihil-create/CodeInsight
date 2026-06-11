#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a;
  cin>>a;
  vector<ll>vec(101,-1);
  vec.at(a)=1;
  for(ll i=0;;i++){
    if(a%2==0){
      a=a/2;
    }
    else{
      a=3*a+1;
    }
    if(a<=100){
      if(vec.at(a)==-1){
        vec.at(a)=1;
      }
    else{
      cout<<i+2<<endl;
      return 0;
    }
  }
  }
}
    
    
  
