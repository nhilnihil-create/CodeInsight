#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <vector>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int a,b;
  cin>>a>>b;
  if(a%2==0 || b%2==0){
    cout<<"Even"<<"\n";
  }
  else{
    cout<<"Odd"<<"\n";
  }
  return 0;
}