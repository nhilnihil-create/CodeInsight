#include <bits/stdc++.h>
using namespace std;
 
int main(){
  long double n,k;
  cin >> n >> k;
  long double ans=0;
  for(int i=1;i<=n;i++){
    int x=i;
    long double y=1/n;
    while(x<k){
      x*=2;
      y/=2.0;
    }
    ans+=y;
  }
  cout << fixed << setprecision(10);
  cout << ans << endl;
}