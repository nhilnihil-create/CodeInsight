#include <bits/stdc++.h>
using namespace std;

int main(){
  int a;
  int ans = 0;
  cin >> a;
  for (int i=0; i < 3; i++) {
    if (a % 10 == 1)
      ans++;
    a = a / 10;
  }
  cout << ans << endl;
  return 0;
}