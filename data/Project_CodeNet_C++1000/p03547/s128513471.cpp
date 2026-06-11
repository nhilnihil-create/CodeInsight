#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  string x,y;
  cin>>x>>y;
  if(x<y){
    cout<<"<"<<"\n";
  }
  else if(x>y){
    cout<<">"<<"\n";
  }
  else{
    cout<<"="<<"\n";
  }
  return 0;
  }