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
  a*=b;
  if(a%2==0){
    cout<<"No"<<"\n";
  }
  else{
    cout<<"Yes"<<"\n";
  }
  
  return 0;
}