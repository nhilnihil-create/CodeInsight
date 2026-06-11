#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b ;
  cin >> a >> b;
  if ( (a+1)/2 == a/2 || (b+1)/2 == b/2) {
    cout << "Even" << endl;
  }
  else {
    cout << "Odd" << endl;
  }
}