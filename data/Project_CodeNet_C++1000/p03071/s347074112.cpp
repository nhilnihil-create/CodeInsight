#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B;
  cin >> A >> B;
  if (A == B)
    cout << A*2 << endl;
  else
    cout << 2*max(A,B) - 1 << endl;
  
}