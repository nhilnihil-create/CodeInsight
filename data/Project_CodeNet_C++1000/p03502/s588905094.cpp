#include <bits/stdc++.h>
using namespace std;
 
int main() {
  
	int N, a, b = 0, X;
	cin >> N;
    X = N;
	for (int i = 0; 1; i++){
      a = X % 10;
      X /= 10;
      b += a;
      if (X < 10){
        b += X;
        break;
      }
    }
  if (N % b == 0){
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}