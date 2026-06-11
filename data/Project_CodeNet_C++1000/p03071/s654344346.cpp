#include <bits/stdc++.h>
using namespace std;

int main(){
  int A, B;
  cin >> A >> B;
  int ans;
  if (A > B) {
    ans += A;
    A--;
  }
  else {
    ans += B;
    B--;
  }
  ans += max(A, B);
  cout << ans << endl;
}