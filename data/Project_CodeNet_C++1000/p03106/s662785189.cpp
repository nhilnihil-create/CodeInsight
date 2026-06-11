#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, k;
  cin >> a >> b >> k;
  
  int count = 0;
  int ans = 101;
  while (true) {
    if (count == k) break;
    ans--;
    if (a % ans == 0 && b % ans == 0) count++;
  }
  cout << ans << endl;
}