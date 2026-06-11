#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, b;
  int a = 0;
  cin >> A >> B;
  for (int i = 0; i < 2; i++)
  {
    a += max(A, B);
    b = max(A, B);
    if (b == A)
    {
      A--;
    }
    else
    {
      B--;
    }
  }
  cout << a << endl;
}