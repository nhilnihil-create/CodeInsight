#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int a,b;
  cin>>a>>b;
  a+=b;
  if(a+b%2!=0){
    a++;
  }
  cout<<a/2<<"\n";
  return 0;
  }