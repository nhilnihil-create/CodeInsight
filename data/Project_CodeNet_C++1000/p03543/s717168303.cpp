#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  
  cin >> N;
  
  if (N % 1111 % 111 <= 1) {
    cout << "Yes" << endl;
  }
  else if (N / 11 % 101 == 0) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}