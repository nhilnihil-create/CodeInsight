#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B;
  cin >> N >> A >> B;

  vector<int> P(N);
  for (int i = 0; i < N; i++) cin >> P.at(i);

  int first = 0;
  int second = 0;
  int third = 0;

  for (int i = 0; i < N; i++) {
    if (P.at(i) <= A)
      first++;
    else if (P.at(i) > A && P.at(i) <= B)
      second++;
    else
      third++;
  }

  cout << min({first, second, third}) << endl;
}