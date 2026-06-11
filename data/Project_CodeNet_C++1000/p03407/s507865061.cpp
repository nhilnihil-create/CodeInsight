#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <vector>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int a,b,c;
  cin>>a>>b>>c;
  a+=b;
  if(a>=c){
    cout<<"Yes"<<"\n";
  }
  else{
    cout<<"No"<<"\n";
  }
  return 0;
}