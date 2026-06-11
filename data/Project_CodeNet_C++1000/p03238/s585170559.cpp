#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <vector>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int c,a,b;
  cin>>c;
  if(c==1){
    cout<<"Hello World"<<"\n";
  }
  else{
    cin>>a>>b;
    a+=b;
    cout<<a<<"\n";
  }
  return 0;
}