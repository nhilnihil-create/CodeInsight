#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long n;
  cin >> n;
  vector<long> ans;
  for(long i=11;ans.size()!=n;i+=10) {
    bool p=true;
    for(long j=2;j*j<=i&&p;j++) {
      if(i%j==0) p=false;
    }
    if(p) ans.push_back(i);
  }
  for(long i=0;i<n;i++) cout << ans[i] << " ";
  cout << endl;
}