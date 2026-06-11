#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, K, m, n=0, ans=0;
  cin >> A >> B >> C >> K;
  
  if (A < B) {
    ans = A;
    m = B;
  } else {
    ans = B;
    m = A;
  }
  if (m < C) {
    ans = ans + m;
    m = C;
  } else ans = ans + C;
  
  do {
    m = m * 2;
    n++;
  } while (n < K);
  
  cout << m+ans << endl;
}