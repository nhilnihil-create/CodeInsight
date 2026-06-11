#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <vector>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int n,a,b;
  cin>>n>>a;
  b=n/500;
  b*=500;
  n-=b;
  if(n<=a){
    cout<<"Yes"<<"\n";
  }
  else{
    cout<<"No"<<"\n";
  }
  return 0;
}