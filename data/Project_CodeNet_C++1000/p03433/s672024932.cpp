#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A;
  cin >> N;
  cin >> A;
  int amari = N % 500;
  if (amari > A) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
}

