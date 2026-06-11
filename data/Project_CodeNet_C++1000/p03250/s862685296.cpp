#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int A, B, C;
  cin >> A >> B >> C;
  
  cout << A+B+C + 9*max(max(A,B),C) << endl;

return 0;
}