#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <vector>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int n;
  long long a;
  cin>>n;
  if(n%2!=0){
    a=n*2;
  }
  else{
    a=n;
  }
  cout<<a<<"\n";
  return 0;
}