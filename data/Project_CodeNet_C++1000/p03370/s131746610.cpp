#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, X, tmp, minM = 1000;
  cin >> N >> X;
  vector<int> m(N);
  for (int i = 0; i < N; i++) {
    cin >> tmp;
    m.at(i) = tmp;
    X -= tmp;
    minM = min(minM, tmp);
  }
  
  int sum = N + X / minM;
  cout << sum << endl;
}
