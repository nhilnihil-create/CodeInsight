#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, X;
  cin >> N >> X;
  vector<int> m(N);
  int minimum = 10000;
  int sum = 0;
  
  for (int i = 0; i < N; i++){
    cin >> m.at(i);
    sum += m.at(i);
    if (m.at(i) < minimum) {
      minimum = m.at(i);
    }
  }
  
  cout << N + (X - sum)/ minimum << endl;
  return 0;
}