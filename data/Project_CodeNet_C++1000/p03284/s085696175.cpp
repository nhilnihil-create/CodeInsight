#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, K;
  cin >> N >> K;
  int ans = N%K;
  if(N<K)ans = 1;
  if(ans > 1) ans = 1;
  cout << ans << endl;
  return 0;
}