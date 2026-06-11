#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  
  int answer = 0;
  
  if (A > B) answer += B;
  else answer += A;
  if (C > D) answer += D;
  else answer += C;
  
  cout << answer << endl;
} 