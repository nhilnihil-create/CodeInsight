#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <vector>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int n,k,ans=0;
  cin>>n>>k;
  ans=n-k+1;
  cout<<ans<<"\n";
  return 0;
}