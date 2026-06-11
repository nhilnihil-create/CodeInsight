#include <bits/stdc++.h>
using namespace std;

int main() {
  int A , B , C , D , E;
  cin >> A;
	B = A/1000;
  	C = A/100%10;
  	D = A/10%10;
  	E = A%10;
  if (C != D ) {
    cout << "No" << endl;
  }
  else if (B == C ) {
    cout << "Yes" << endl;
  }
  else if (D == E ) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}
