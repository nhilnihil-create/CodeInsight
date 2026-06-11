#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N + 2, 0);
  for (int i = 1; i <= N; i++) {
    cin >> A.at(i);
  }
  
  int S = 0;
  for (int i = 1; i <= N + 1; i++) {
    S += abs(A.at(i) - A.at(i - 1));
  }
  
  for (int i = 1; i <= N; i++) {
    cout << S + abs(A.at(i + 1) - A.at(i - 1))
      - abs(A.at(i) - A.at(i - 1)) - abs(A.at(i + 1) - A.at(i)) << endl;
  }
}
