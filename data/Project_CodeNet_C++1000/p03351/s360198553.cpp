#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  int n,m;
  n=max(a,b)-min(a,b);
  m=max(b,c)-min(b,c);
  bool ok=false;
  if((max(a,c)-min(a,c))<=d){
    ok=true;
  }
  else if(n<=d && m<=d){
    ok=true;
  }
  if(ok){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
  return 0;
}