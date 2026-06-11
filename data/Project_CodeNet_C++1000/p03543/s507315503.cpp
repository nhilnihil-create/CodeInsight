#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  
  int n123 = n / 10;
  int n234 = n % 1000;
  
  if (n123 % 111 == 0 || n234 % 111 == 0) { cout << "Yes" << endl; }
  else { cout << "No" << endl; }
}