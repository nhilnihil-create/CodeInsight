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
  if(a<=5){
    b=0;
  }
  else if(a<=12){
    b/=2;
  }
  cout<<b<<"\n";
  
  return 0;
}