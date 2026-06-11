#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int nInput;
  cin >> nInput;
  int a = nInput % 10;
  int b = nInput / 10;
  int c = b % 10;
  int d = b / 10;
  int e = d % 10;
  cout << a + c + e << endl;
  
}