#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
//  cout << N << endl;

  uint64_t tmp0 = 2;
  uint64_t tmp1 = 1;
  uint64_t result = 1;
    
  for (int i=1; i<N; ++i) {
    result = tmp1 + tmp0;
    tmp0 = tmp1;
    tmp1 = result;
  }
  
  cout << result << endl;
  
  return 0;
}