#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N, A;
  cin >> N >> A;
  int X = N % 500;
  if (X <= A) {
    cout << "Yes" << endl;
  }
  
  else {
    cout << "No" << endl;
  }
}