#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, ans;
  cin >> A;
  ans = 0;
  if(A % 10 == 1) {
    ans += 9;
  }
  else {
    ans += 1;
  }
  if((A + 10) % 100 <= 10) {
    ans += 10;
  }
  else {
    ans += 90;
  }
  if((A + 100) % 1000 <= 100) {
    ans += 100;
  }
  else {
    ans += 900;
  }
  cout << ans << endl;
}
