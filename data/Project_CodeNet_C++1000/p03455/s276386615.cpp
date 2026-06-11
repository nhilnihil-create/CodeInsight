#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b; 
  
  if (a * b / 2 * 2 == a * b * 0.5 * 2 ) {
  cout << "Even" << endl;
  }
  if (a * b / 2 * 2 != a * b * 0.5 * 2 ) {
  cout << "Odd" << endl;
  }
}