#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int i;
  cin >> i;
  int one = i / 1000;
  int two = (i - one * 1000) / 100;
  int three = (i - one * 1000 - two * 100) / 10;
  int four = (i - one * 1000 - two * 100 - three * 10) / 1;
  if ((one == two && two == three) || (two == three && three == four)) {
    cout << "Yes";
  } else {
    cout << "No"; 
  }
}
