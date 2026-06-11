#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int n,a,b;
  cin>>n>>a>>b;
  cout<<min((n*a),b)<<"\n";
  return 0;
  }