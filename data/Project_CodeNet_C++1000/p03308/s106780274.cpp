#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  
  int min = 1000000000, max = 1;
  for (auto e : A) {
    if (e < min) min = e;
    if (e > max) max = e;
  }
  
  cout << max - min << endl;
}
