#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,ans=0;
  cin >> n;
  for(long i=1;true;i++) {
    if((n-i)/i<=i) break;
    if((n-i)%i==0) {
      ans+=(n-i)/i;
    }
  }
  cout << ans << endl;
}