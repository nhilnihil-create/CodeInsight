#include <bits/stdc++.h>
using namespace std;

int main () {
  int A, B, ans = 1;
  cin >> A >> B;
  string S;
  cin >> S;
  for (int i = 0; i < A; i++) {
    if (!('0' <= S[i] && S[i] <= '9')) ans = 0;
  }
  if (S[A] != '-') ans = 0;
  for (int i = A+1; i < A+B+1; i++) {
    if (!('0' <= S[i] && S[i] <= '9')) ans = 0;
  }
  if (ans) printf("Yes");
  else printf("No");
  return 0;
}
 
