#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a, b;
  cin >> a >> b;
  int count = a - 1;

  if (a <= b) {
    count = count + 1 ;
  }

  cout << count << endl;
}