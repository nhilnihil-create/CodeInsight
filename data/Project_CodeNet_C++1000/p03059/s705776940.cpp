#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,T,ans=0; cin >> A >> B >> T;
  if(A>T) {
    cout << 0 << endl;
    return 0;
  }
  else {
    while(T>=A) {
      ans += B;
      T -= A;
    }
  }
  cout << ans << endl;
}