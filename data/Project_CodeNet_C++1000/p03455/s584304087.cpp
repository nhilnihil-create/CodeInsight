#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A;
  cin >> N >> A;

  if ( N*A %2 == 0 ) {
    cout << "Even" << endl;
  }
  if ( N*A %2 == 1 ) {
    cout << "Odd" << endl;
  }

}