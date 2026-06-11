#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,absmax=0,absmaxi=0;
  cin >> n;
  vector<long> a(n),ans1,ans2;
  for(long i=0;i<n;i++) cin >> a[i];
  
  for(long i=0;i<n;i++) {
    if(absmax<abs(a[i])) {
      absmax=abs(a[i]);
      absmaxi=i;
    }
  }
  for(long i=0;i<n;i++) {
    if(i==absmaxi) continue;
    ans1.push_back(absmaxi+1);
    ans2.push_back(i+1);
  }
  if(a[absmaxi]>0) {
    for(long i=0;i<n-1;i++) {
      ans1.push_back(i+1);
      ans2.push_back(i+2);
    }
  } else if(a[absmaxi]<0) {
    for(long i=n-2;i>=0;i--) {
      ans1.push_back(i+2);
      ans2.push_back(i+1);
    }
  }
  cout << ans1.size() << endl;
  for(long i=0;i<ans1.size();i++) cout << ans1[i] << " " << ans2[i] << endl;
}