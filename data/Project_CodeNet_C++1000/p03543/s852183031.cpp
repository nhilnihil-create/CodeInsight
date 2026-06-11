#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int digit4 = N / 1000;
  int digit3 = (N % 1000) / 100;
  int digit2 = (N % 100) / 10;
  int digit1 = N % 10;
  
  if ((digit4 == digit3)
      && (digit4 == digit2)
     ){
    cout << "Yes" << endl;
  }
  else if ((digit3 == digit2)
      && (digit3 == digit1)
     ){
    cout << "Yes" << endl;
  }
  else {
  	cout << "No" << endl;
  }
}