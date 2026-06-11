#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int s, count = 0;
  cin >> s;
  if (s / 100 == 1) {
      count += 1;
  }
  if ((s % 100) / 10 == 1) {
      count += 1;
  }
  if (s % 10 == 1) {
      count += 1;
  }
  
  cout << count << endl;
}