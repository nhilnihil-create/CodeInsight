#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B;
  cin >> N >> A;
  
  B = N % 500;
  
  if (A < B) {
    cout << "No" << endl;
  }
  else if (A >= B) {
    cout << "Yes" << endl;
  }
}