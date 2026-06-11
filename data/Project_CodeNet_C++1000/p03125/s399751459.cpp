#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll int64_t
#define all(v) v.begin(), v.end()
#define bitrep(n) for(int bit=0;bit<(1<<n);bit++)

int main() {
  int A,B;
  cin >> A >> B;

  if(B%A==0) cout << A+B << endl;

  else if(B%A!=0) cout << B-A << endl;
  
  return 0;
}