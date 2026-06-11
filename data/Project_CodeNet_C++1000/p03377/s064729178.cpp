#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, K;
  cin >> A >> B >> K;
  
  if ((A+B >= K) && (A <= K)) cout << "YES" << endl;
  else cout << "NO" << endl;
} 