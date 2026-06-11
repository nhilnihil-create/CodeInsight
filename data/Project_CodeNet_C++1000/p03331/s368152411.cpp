#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c=0;
  cin>>a;
  b=a;
  c+=a%10;
  while(a>=10){
    a=a/10;
    c+=a%10;
  }
  if(c==1&&b>1){
    cout<<10<<endl;
  }
  else{
    cout<<c<<endl;
  }
}