#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int64_t lucas(int N) {
  vector<int64_t> L = {2, 1};

  for (int i = 2; i < N + 1; i++) {
    L.push_back( L.at(i-1) + L.at(i-2) );
  }
  return L.at(N);
/*
  // Recursive function results in TLE.
  if (N < 0) {
    return 0;
  }
  else if (N == 0) {
    return 2;
  }
  else if (N == 1) {
    return 1;
  }
  return lucas(N-1) + lucas(N-2);
*/
}

int main() {
  int N;
  cin >> N;

  cout << lucas(N) << "\n";
}
