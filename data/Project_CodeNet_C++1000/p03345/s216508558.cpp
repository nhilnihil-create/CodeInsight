#include <bits/stdc++.h>
using namespace std;


int main() {

  int64_t a,b,c,k;
  cin>>a>>b>>c>>k;

  //偶数回はA-B
  //奇数回はB-A

  int64_t out;
  if(k%2==0){
    out=a-b;
  }else{
    out=b-a;
  }

  if(abs(out)>1000000000000000000)
    cout<<"Unfair"<<endl;
  else
    cout<<out<<endl;

  return 0;
}