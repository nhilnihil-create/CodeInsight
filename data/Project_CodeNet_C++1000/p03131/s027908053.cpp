#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t K, A, B;
  cin >> K >> A >> B;
  int64_t sa = B-A;
  int64_t ans =0;
  if(sa >2 && K>=A+1){
    ans = (K-A+1)/2*sa + (K-A+1)%2 +A;
  }
  else ans = K+1;
  
  cout << ans << endl;
}