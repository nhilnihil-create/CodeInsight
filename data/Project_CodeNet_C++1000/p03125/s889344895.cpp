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
  if(b%a==0){
    cout<<a+b<<"\n";
  }
  else{
    cout<<b-a<<"\n";
  }
  return 0;
}