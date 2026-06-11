#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, sum;
  cin >> a;
  cin >> b;
  
  sum = a + b;
  double result = sum / 2 + sum % 2;
  cout << result << endl;
}