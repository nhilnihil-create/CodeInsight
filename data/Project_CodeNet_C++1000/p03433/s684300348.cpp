#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A;
  cin >> N >> A;
  int ans =0;
  ans =A - (N % 500);
  if (ans >= 0) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}
