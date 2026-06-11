#include <bits/stdc++.h>
using namespace std;


int main() {

  int64_t a,b,k;
  cin>>a>>b>>k;

  for(int i=0;i<k;i++){
    if(i%2==0){
      if(a%2!=0)
        a--;

      b+=a/2;
      a/=2;
    }else{
      if(b%2!=0)
        b--;

      a+=b/2;
      b/=2;
    }
  }

  cout<<a<<' '<<b<<endl;

  return 0;
}
