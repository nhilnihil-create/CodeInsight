#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c;
  cin>>a>>b>>c;
  for(int i=0;i<c;i++){
    if(i%2==0){
      if(a%2==1){
        a--;
      }
      b+=a/2;
      a=a/2;
    }
    else{
      if(b%2==1){
        b--;
      }
      a+=b/2;
      b=b/2;
    }
  }
  cout<<a<<' '<<b<<endl;
}