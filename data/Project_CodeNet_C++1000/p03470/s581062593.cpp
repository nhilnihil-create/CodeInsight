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
  int A = 1;
  for (int i = 0; i < N - 1; i++) {
    if (changed.at(i) > changed.at(i + 1)) {A++;}
  }
  cout << A << endl;
}