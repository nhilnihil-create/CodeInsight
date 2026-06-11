#include<iostream>
using namespace std;
int main()
{
  int a,b,c,d,e,f;
  cin>>a>>b;
  cin>>c>>d;
  cin>>e>>f;
  if(a==c||a==d){
    if(a==e||a==f){
      cout<<"NO";
    }
    else{
      cout<<"YES";
    }
  }
  else if(b==c||b==d){
    if(b==e||b==f){
      cout<<"NO";
    }
    else{
      cout<<"YES";
    }
  }
  else if(a==e||a==f){
    if(a==c||a==d){
      cout<<"NO";
    }
    else{
      cout<<"YES";
    }
  }
  else if(b==e||b==f){
    if(b==c||b==d){
      cout<<"NO";
    }
    else{
      cout<<"YES";
    }
  }
}