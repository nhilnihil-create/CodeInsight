#include<bits/stdc++.h>
using namespace std;
signed main(){
int a,b;
  cin>>a>>b;
  if(a+b==15) cout<<"+";
  if(a*b==15) cout<<"*";
  if(a+b!=15&&a*b!=15) cout<<"x";
  cout<<"\n";
}