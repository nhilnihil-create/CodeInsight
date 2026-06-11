#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  int ans;
  cin >> A >> B;

  if (B%A==0)
  {
      ans = A+B;
  }
  else
  {
      ans = B-A;
  }
  cout << ans << endl;
}
