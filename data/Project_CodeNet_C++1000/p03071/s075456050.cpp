#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B,ans;
  cin >> A >> B;
  ans = max(A,B);
  if (A == B) ans += A;
  else  ans += max(A,B)-1;
  cout << ans;
  

}
