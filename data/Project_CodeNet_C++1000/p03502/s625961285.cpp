#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, count, t;
  cin >> N;
  count = 0;
  t = N;
  for (int i=0; t > 0; i++) {
    count += t % 10;
    t /= 10;
  }
  if (N % count == 0) {
    cout << "Yes" << endl; 
  }
  else {
    cout << "No" << endl;
  }
  
}