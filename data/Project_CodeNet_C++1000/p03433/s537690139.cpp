#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, N;
  cin >> N >> A;
  
  N = N % 500;
  
  if (N > A)  cout << "No" << endl;
  else cout << "Yes" << endl;
}
