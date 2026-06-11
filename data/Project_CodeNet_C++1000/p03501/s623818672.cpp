#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  int C = A * N;

  if (C <= B) {
    cout << C << endl;
  }

  if (C > B) {
    cout << B << endl;
  }
  
}