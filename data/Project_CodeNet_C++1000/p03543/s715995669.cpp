#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int x = N % 10;
  int y = N % 1000;
  if ( (N - x)  % 1110 == 0) {
    cout << "Yes" << endl;
  }
  else if (y % 111 == 0) {
    cout << "Yes" <<endl;
  }
  else {
    cout << "No" <<endl;
 }
}