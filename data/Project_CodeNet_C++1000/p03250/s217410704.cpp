#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <vector>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int a[5],ans;
  for(int i=0;i<3;i++){
    cin>>a[i];
  }
  sort(a,a+3);
  ans=a[2]*10;
  ans+=a[0]+a[1];
  cout<<ans<<"\n";
  
  return 0;
}