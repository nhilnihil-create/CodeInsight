#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
  int K,A,B;
  cin >> K >> A >> B;
  if((B-A) <= 2 || K-B >= A){
    cout << K+1 << endl;
    return 0;
  }
  else{
    int ans = 1;
    K -= A-1;
    ans = A;
    ans += (K/2)*(B-A);
    if(K%2 == 1){
      ans++;
    }
    cout << ans << endl;
  }
}
