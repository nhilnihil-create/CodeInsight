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
  c/=a;
  c*=b;
  cout<<c<<"\n";
  return 0;
}