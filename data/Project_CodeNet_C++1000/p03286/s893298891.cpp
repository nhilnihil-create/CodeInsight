#include<bits/stdc++.h>
using namespace std;
int main(){
  int z;
  string s="";
  bool f=false;
  cin>>z;
  while(f==false){
    if(z%2==0) s='0'+s;
    else{
      s='1'+s;
      z--;
    }
    z/=-2;
    if(z==0) f=true;
  }
  cout<<s<<endl;
}