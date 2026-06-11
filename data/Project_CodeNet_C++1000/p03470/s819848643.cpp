#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,ans=0;
  cin >> n;
  ans=n;
  vector<long> a(n);
  for(long i=0;i<n;i++) cin >> a[i];
  sort(a.begin(),a.end());
  for(long i=1;i<n;i++) if(a[i-1]==a[i]) ans--;
  cout << ans << endl;
}