#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n,k;
  cin >> n >> k;
  long long ans=0;
  
  for(int b=k+1;b<=n;b++){
    int p=n/b;
    ans+=(b-k)*p;
    if(n%b!=0) ans+=max(0,(n-p*b)-max(k,1)+1);
  }
  
  cout << ans << endl;
}