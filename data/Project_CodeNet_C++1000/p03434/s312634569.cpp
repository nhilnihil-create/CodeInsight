#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
  for (int i = 0; i < N; i++) {
    cin >> vec.at(i);
  }
  vector<int> changed(N);
  for (int i = 0; i < N; i++) {
    int S = 0, k = 0;
    for (int j = 0; j < N; j++) {
      if (vec.at(j) > S) {
        S = vec.at(j);
        k = j;
      }
    }
    changed.at(i) = S;
    vec.at(k) = 0;
  }
  int A = 0;
  for (int i = 0; i < N / 2 + N % 2; i++) {
    A += changed.at(2 * i);
  }
  for (int i = 0; i < N / 2; i++) {
    A -= changed.at(2 * i + 1);
  }
  cout << A << endl;
}