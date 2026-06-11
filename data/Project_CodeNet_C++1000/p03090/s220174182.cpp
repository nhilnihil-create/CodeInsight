#include <bits/stdc++.h>
using namespace std;

int main() {
  long n;
  cin >> n;
  vector<long> ansa,ansb;
  if(n%2==0) {
    for(long i=1;i<=n;i++) {
      for(long j=i+1;j<=n;j++) {
        if(i!=j&&i+j!=n+1) {
          ansa.push_back(i);
          ansb.push_back(j);
        }
      }
    }
  } else {
    for(long i=1;i<=n-1;i++) {
      for(long j=i+1;j<=n-1;j++) {
        if(i!=j&&i+j!=n) {
          ansa.push_back(i);
          ansb.push_back(j);
        }
      }
      ansa.push_back(i);
      ansb.push_back(n);
    }
  }
  cout << ansa.size() << endl;
  for(long i=0;i<ansa.size();i++) cout << ansa[i] << " " << ansb[i] << endl;
}