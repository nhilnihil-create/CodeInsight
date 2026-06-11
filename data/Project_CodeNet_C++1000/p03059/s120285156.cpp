#include<bits/stdc++.h>
using namespace std;

int main(void){
  int A, B, T, _A, ans = 0;
  cin >> A >> B >> T;
  int cnt = 1;
  while(1){
    _A = A * cnt;
    if(_A > T + 0.5)
      break;
    ans += B;
    cnt++;
  }
  cout << ans << "\n";
  return 0;
}
