#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  int tot = pow(3, N);
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }

  int cnt = 1;
  for (int i = 0; i < N; i++) {
    if (A.at(i) % 2 == 0) cnt *= 2;
  }

  cout << tot - cnt << endl;
}
