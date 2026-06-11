#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  int a;
  int b;
  cin >> n;
  cin >> a;
  cin >> b;
  
  int t = n * a;
  
  if (t > b ) {
    cout << b << endl;
  }
  else if (t < b ) {
    cout << t << endl;
  }
  else if (t = b ) {
    cout << b << endl;
  }
}
