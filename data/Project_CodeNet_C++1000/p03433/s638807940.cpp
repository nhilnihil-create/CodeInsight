#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a, b;
  cin >> a >> b;
  int mod500 = a % 500;
  if (b >= mod500) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl; 
  }
}