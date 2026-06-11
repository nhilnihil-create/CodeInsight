#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  
  int min = (int)(pow(10, 9) + 1);
  int max = 0;
  for (auto a : A) {
    if (a > max) max = a;
    if (a < min) min = a;
  }
  cout << (max - min) << endl;
}