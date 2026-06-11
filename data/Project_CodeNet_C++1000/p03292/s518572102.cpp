#include <bits/stdc++.h>
using namespace std;

int main() {
  int a[3];
  for(int i = 0; i < 3; i++){
    cin >> a[i];
  }
  sort(a,a+3);
  int ans = 0;
  for(int i = 1; i < 3; i++){
    ans += abs(a[i-1] - a[i]);
  }
  cout << ans << endl;
  return 0;
}