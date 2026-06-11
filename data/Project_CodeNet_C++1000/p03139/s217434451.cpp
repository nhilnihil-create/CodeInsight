#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  if(c>=b)
    cout<<b<<endl;
  else
    cout<<c<<endl;
  if(b+c-a>0)
    cout<<b+c-a<<endl;
  else
    cout<<"0"<<endl;
  return(0);
}