#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <vector>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int h,w,x,y;
  int ans;
  cin>>h>>w>>x>>y;
  ans=h-x;
  ans*=w-y;
  cout<<ans<<"\n";
  return 0;
}