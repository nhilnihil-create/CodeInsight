#include<bits/stdc++.h>
using namespace std;
signed main(){
  int a,b;
  cin>>a>>b;
  if(a+b==15){
    cout<<"+\n";
  }
  if(a*b==15){
    cout<<"*\n";
  }
  if(a+b!=15 && a*b!=15){
    cout<<"x\n";
  }
}
