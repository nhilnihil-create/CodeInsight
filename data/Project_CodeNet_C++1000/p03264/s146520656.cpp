#include<bits/stdc++.h>
using namespace std;

int main(void){
  int K;
  int ki,gu;
  int ans;
  cin >> K;
  gu = K / 2;
  ki = K - gu;
  ans = gu * ki;
  cout << ans << "\n";
  return 0;
}
