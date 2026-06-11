#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;


int main(void){
  int n,i,a[200005];
  ll ans=0;
  
  cin >> n;
  for (i=0;i<n;i++) cin >> a[i];
  
  if (a[0]!=0){
    cout << -1 << endl;
    return 0;
  }
  
  for (i=0;i<n-1;i++){
    if (a[i+1]-a[i]>1){
      cout << -1 << endl;
      return 0;
    }
  }
  
  while (i>=0){
    ans+=a[i];
    while (i>=0 && a[i]-a[i-1]==1) i--;
    i--;
  }
  
  cout << ans << endl;
  
  return 0;
}