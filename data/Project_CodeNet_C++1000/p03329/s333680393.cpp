#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long n,ans=9999999999;
  cin >> n;
  for(long i=0;i<=n;i++) {
    long a=0;
    for(long j=1;j<=i;j*=6) a+=i/j%6;
    for(long j=1;j<=n-i;j*=9) a+=(n-i)/j%9;
    ans=min(ans,a);
  }
  cout << ans << endl;
}