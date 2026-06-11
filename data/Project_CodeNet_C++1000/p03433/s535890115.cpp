#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  int A;
  int x;
  cin >> N >> A;
  x = N%500;
  if (A >= x) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}
