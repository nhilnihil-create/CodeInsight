#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int s, x;
  cin >> s;
//  x = s/100 + (s/10 - s/100 * 10) + (s/1 - s/10 * 10);
  x = s - s/10 * 9 - s/100 * 9;
  cout << x << endl;
}