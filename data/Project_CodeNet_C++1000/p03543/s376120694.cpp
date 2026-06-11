#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, N1, N2, N3, N4;
  cin >> N;
  
  if (N / 10 % 111 == 0) {
    cout << "Yes" << endl;
  }
  else if ((N - (N / 1000) * 1000) % 111 == 0) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}