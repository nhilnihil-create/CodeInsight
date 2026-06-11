#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, p1, p2;
  cin >> N >> A ;

  p1 = N / 500;
  p2 = N - p1 * 500;
  
  if (p2 > A) {
    cout << "No" << endl;
  }
  else {
    cout << "Yes" << endl;
  }
}
