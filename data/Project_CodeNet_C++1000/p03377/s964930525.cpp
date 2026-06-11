#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b,x;
  cin>>a>>b>>x;
  bool ok=false;
  if(x>=a){
    if(x-a<=b){
      ok=true;
    }
  }
  if(ok){
    cout<<"YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }
  return 0;
}
      
