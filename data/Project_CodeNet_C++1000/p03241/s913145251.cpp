#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,m,ans=0;
  cin >> n >> m;
  for(long i=1;i*i<=m;i++) {
    if(m%i==0) {
      if(m/i>=n) ans=max(ans,i);
      if(i>=n) ans=max(ans,m/i);
    }
  }
  cout << ans << endl;
}