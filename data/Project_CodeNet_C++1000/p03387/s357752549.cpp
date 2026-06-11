#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  int A,B,C;
  cin >> A >> B >> C;
  int ans = 0;
  while(A != B || B != C || ans%2 != 0){
    ans++;
    if(A<=B && A<=C){
      A++;
    }
    else if(B<=C && B<=A){
      B++;
    }
    else{
      C++;
    }
  }
  cout << ans/2 << endl;
}
