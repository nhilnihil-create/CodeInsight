#include <bits/stdc++.h>
using namespace std;

int main() {
  int a = 0;
  
  cin >> a;
  cout << (a % 2) + (a / 10 % 2) + (a / 100 % 2) << endl;
}