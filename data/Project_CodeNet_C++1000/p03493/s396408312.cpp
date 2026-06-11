#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int abc;
  cin >> abc;
  int a = abc / 100;
  int b = (abc - a * 100) / 10;
  int c = (abc - a * 100 - b * 10) / 1;
  cout << a + b + c << endl;
}