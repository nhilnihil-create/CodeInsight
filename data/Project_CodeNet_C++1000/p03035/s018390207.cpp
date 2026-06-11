#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A, B;
  cin >> A >> B;
  int result = 0;
  if (A >= 13) {
    result = B;
  }
  else if (A >= 6) {
    result = B / 2;
  }
  
  cout << result << endl;
    
  return 0;
}