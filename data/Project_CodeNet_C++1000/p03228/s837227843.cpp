#include <bits/stdc++.h>
using namespace std;

int main() {
  long long int a,b,k;
  cin>>a>>b>>k;
  
  for(int i=0;i<k;i++){
    if(i%2==0){
      if(a%2==1){
        a-=1;
      }
      b+=a/2;
      a/=2;
    }
    if(i%2==1){
      if(b%2==1){
        b-=1;
      }
      a+=b/2;
      b/=2;
    }
  }
  cout<<a<<" "<<b<<endl;    
}