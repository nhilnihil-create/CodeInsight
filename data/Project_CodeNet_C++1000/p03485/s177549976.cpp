#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a, b, mean, remainder;
  cin >> a >> b;
  mean = (a+b)/2;
  remainder = (a+b)%2;
  cout << (mean+remainder) << endl;
}