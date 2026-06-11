#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, A, E;

  cin >> N;
  cin >> A;
 
  E = N % 500;
  if (E != 0) {
    if (A - E >= 0){
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }
  }
  else {
    cout << "Yes" << endl;
  }
}