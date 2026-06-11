#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A;
  cin >> N >> A;
  if (N >= 500) {
    N = N - (N / 500) * 500;
  }
  if (N <= A) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}