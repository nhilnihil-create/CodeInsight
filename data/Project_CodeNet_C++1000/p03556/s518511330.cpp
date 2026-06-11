#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N; cin >> N;
  
  for (int i = 1; i < 100001; i++) {
    
    int tmp = pow(i, 2);
    
    if (N < tmp) {
      cout << (i - 1) * (i - 1) << endl;
      return 0;
    }
    
  }
  
}