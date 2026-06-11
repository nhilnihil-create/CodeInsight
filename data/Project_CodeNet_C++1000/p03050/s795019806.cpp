#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;


int main(void){
  ll n,d,m,ans=0;
  
  cin >> n;
  
  for (d=1;d*(d+2)<=n;d++){
    if (n%d==0) ans+=n/d-1;
  }
  
  cout << ans << endl;
  
  return 0;
}