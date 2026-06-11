#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a, b;
  cin >> a >> b;
  cout << int (double (a + b) / 2 + (1 - pow(-1, a + b)) / 4) << endl;
}