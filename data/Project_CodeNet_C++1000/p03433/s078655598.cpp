#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a, b, c;
  cin >> a >> b;
  c = a/500;
  c = a-500*c;
  if (c<=b) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}