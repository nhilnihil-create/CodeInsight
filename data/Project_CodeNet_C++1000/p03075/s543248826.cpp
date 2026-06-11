#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
  int a,b,c,d,e,k;
  cin>>a>>b>>c>>d>>e>>k;
  bool connect=true;
  if(b-a>k||c-a>k||d-a>k||e-a>k||c-b>k||d-b>k||e-b>k||d-c>k||e-c>k||e-d>k){
      connect=false;
  }
  if(connect==true){
      cout<<"Yay!"<<endl;
  }
  else{
      cout<<":("<<endl;
  }
  
}