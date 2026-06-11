#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, P1a, P1b, P2a, P2b;
  cin >> N;
  
  P1a = N % 1000;
  P1b = P1a % 111;
  
  P2a =  N / 10;
  P2b = P2a % 111;
  
  
	if (P1b == 0 || P2b == 0) {
		cout << "Yes" << endl;
    }
  else {
      cout << "No" << endl;
  } 
}