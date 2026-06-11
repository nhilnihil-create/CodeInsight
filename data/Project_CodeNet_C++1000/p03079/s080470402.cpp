#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b,c;
  cin >> a >> b >> c;
  
  if (a == b  && a == c) {
    cout << "Yes" << endl;
  }
  
  if (a != b || a != c) {
    cout << "No" << endl;
  }
}