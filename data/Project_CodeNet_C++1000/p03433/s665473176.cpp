#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A;
  cin >> N >> A;

  if (N <= A) {
    cout << "Yes" << endl;
  }
  else if (N % 500 <= A) {
    cout << "Yes" << endl;
  }
  else cout << "No" << endl;
}