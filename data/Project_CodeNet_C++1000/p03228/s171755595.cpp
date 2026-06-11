#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll a,b,k;
  cin>>a>>b>>k;
  for(int i=0;i<k;i++){
    if(i%2){
      if(b%2)b--;
      a+=b/2;
      b/=2;
    }
    else{
      if(a%2)a--;
      b+=a/2;
      a/=2;
    }
  }
  cout<<a<<' '<<b<<endl;
}