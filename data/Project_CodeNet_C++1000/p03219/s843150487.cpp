#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <vector>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int x,y;
  cin>>x>>y;
  x+=y/2;
  cout<<x<<"\n";
  return 0;
}