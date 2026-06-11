#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  int A, B, C;
  cin >> A >> B >> C;
  
  int ans = 0;
  if( B >= C ){
    ans += B+C;
    cout << ans << endl;
    return 0;
  }else{
    ans += B*2;
    if( A >= C-B ){
      ans += C-B;
      cout << ans << endl;
      return 0;
    }else{
      ans += A+1;
      cout << ans << endl;
      return 0;
    }
  }
  

}

