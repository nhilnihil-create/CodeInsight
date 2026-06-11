#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,k;
  cin  >> n >> k;
  int cnt = 0;
  for(int i = 1; i <= n; i++){
    if(i % 2 == 1) cnt++;
  }
  if(cnt >= k) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}