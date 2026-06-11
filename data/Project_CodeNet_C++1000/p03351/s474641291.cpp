#include<iostream>
using namespace std;
int main(){
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  bool no=true;
  if((abs(b-a)<=d&&abs(c-b)<=d)||(abs(c-a)<=d))
  { 
    no=false;
  }
  if(no){
    cout<<"No\n";
  }
  else{
    cout<<"Yes";
  }
}