#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a;
  cin >> a;
  
  bitset <3> b(a);

  int count = 0;
  
  for (int i; i < 3; i++) {
    if (b.test(i)) {
      count++;
    }
  }
  
  cout << count << endl;
  
}
