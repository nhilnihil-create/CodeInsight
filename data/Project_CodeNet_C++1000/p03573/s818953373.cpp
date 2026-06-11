#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  int ans = 0;
  if(A == B) ans = C;
  else if(B == C) ans = A;
  else if(C == A) ans = B;

  cout << ans; 
  return 0;
}

