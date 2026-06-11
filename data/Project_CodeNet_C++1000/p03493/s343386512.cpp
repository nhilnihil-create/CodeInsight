#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int num;
  cin >> num;
  int a = num / 100; 
  int b = num / 10 - (a * 10);
  int c = num - (a * 100) - (b * 10);
  cout << a + b + c << endl;
}