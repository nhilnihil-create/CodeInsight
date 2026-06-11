#include <bits/stdc++.h>
using namespace std;

int main() {
  long n;
  bool bo=true;
  cin >> n;
  vector<long> b(n);
  vector<long> x(n);
  vector<long> ans;
  for(long i=0;i<n;i++) cin >> b[i];

  for(long i=0;i<n;i++) x[i]=i+1;

  while(bo) {
    bo=false;
    for(long i=n-1;i>=0;i--) {
      if(b[i]==x[i]) {
        bo=true;
        ans.push_back(x[i]);
        for(long j=i;j<n;j++) {
          x[j]--;
        }
        break;
      }
    }
  }

  if(ans.size()==n) for(long i=ans.size()-1;i>=0;i--) cout << ans[i] << endl;
  else cout << -1 << endl;
}