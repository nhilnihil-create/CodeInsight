#include <bits/stdc++.h>
using namespace std;

int main() {

  int N;
  int A[10000000];

  cin >> N;

  for (int i = 0 ; i < N ; i++) {
    cin >> A[i];
  }

  int MAX = 0;
  for (int i = 0 ; i < 1000000 ; i++) {
    int isBroken = 0;
    // cout << "[";
    for (int j = 0 ; j < N ; j++) {
      // cout << A[j] << " ";
      if (A[j] % 2 != 0) {
	// cout << A[j] << endl;
	isBroken = 1;
	break;
      }
      A[j] = A[j]/2;
    }
    // cout << "]" << endl;
    if (isBroken == 1) {
      break;
    }
    MAX++;
  }

  cout << MAX << endl;
 
}
