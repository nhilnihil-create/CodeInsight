#include <iostream>
using namespace std;
int main(){
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  int right=a+b;
  int left=c+d;
  string ret;
  if(right>left){
    ret="Left";
  }else if(right==left){
    ret="Balanced";
  }else{
    ret="Right";
  }
  cout<<ret;
  return 0;
}