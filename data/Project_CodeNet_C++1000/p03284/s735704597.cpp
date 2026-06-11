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
  if(n%k!=0){
    ans++;
  }
  cout<<ans<<"\n";
  return 0;
}