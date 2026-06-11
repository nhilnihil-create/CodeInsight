#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N;
  cin >> N;
  
  int n1 = N / 1000;
  int n2 = N / 100 % 10;
  int n3 = N / 10 % 10;
  int n4 = N % 10;
  
  if (n1 == n2 && n2 == n3) {
    cout << "Yes" << endl;
  }
  
  else if (n2 == n3 && n3 == n4) {
    cout << "Yes" << endl;
  }
  
  else cout << "No" << endl;
  
}  