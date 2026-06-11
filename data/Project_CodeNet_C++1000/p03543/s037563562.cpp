#include <bits/stdc++.h>
using namespace std;
 
int main() {
  
  int n;
  cin >> n;
  
  int a = n / 1000;
  int b = n % 1000;
  
  int c = b / 100;
  int d = b % 100;
  
  int e = d / 10;
  
  int f = d % 10;
  
  if (a == c && a == e) {
    cout << "Yes" << endl;
  }
  
  else if (c == e && c == f) {
    cout << "Yes" << endl;
  }
  
  else {
    cout << "No" << endl;
  }
  
}