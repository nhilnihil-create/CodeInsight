#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N;
  cin >> N;
  
  vector<int64_t> numl(N + 1);
  numl.at(0) = 2;
  numl.at(1) = 1;
  
  int64_t L_i = 0;
  
  for (int i; i < N - 1; i++) {
    numl.at(i + 2) = numl.at(i + 1) + numl.at(i);
  }
  
  cout << numl.at(N) << endl;
}