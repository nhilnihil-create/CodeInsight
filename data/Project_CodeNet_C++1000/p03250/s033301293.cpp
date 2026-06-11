#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef long long Int;


int main() {
  vector<Int> A(3);
  cin >> A[0] >> A[1] >> A[2];
  sort(A.begin(), A.end());
  
  Int x,y;
  x = A[2] * 10 + A[1];
  y = A[0];
  
  cout << x + y << endl;
  
}