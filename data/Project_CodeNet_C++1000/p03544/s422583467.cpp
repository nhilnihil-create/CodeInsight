#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N;
  cin >> N;
  
  if (N == 0) {
    cout << 2 << endl;
    return 0;
  } else if (N == 1) {
    cout << 1 << endl;
    return 0;
  }
  
  vector<int64_t> lucas(N+1);
  lucas.at(0) = 2;
  lucas.at(1) = 1;
  
  for (int64_t i = 2; i < N+1; i++) {
    lucas.at(i) = lucas.at(i-1) + lucas.at(i-2);
  }
  
  cout << lucas.at(N) << endl;
}