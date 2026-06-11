#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  a+=b;
  c+=d;
  if(a==c){
    cout<<"Balanced"<<"\n";
  }
  else if(a>c){
    cout<<"Left"<<"\n";
  }
  else{
    cout<<"Right"<<"\n";
  }
  return 0;
  }