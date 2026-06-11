#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int r,g;
  cin>>r>>g;
  g*=2;
  g-=r;
  cout<<g<<"\n";
  
  return 0;
}