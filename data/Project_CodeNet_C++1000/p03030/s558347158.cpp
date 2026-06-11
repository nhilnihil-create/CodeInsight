#include <bits/stdc++.h>
using namespace std;

int main() {
  using pii = pair<string, int>;
  
  int N;
  cin >> N;
  vector<pii> A(N), B(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i).first >> A.at(i).second;
    B.at(i).first = A.at(i).first;
    B.at(i).second = - A.at(i).second;
  }
  
  sort(B.begin(), B.end());
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (B.at(i).first == A.at(j).first && B.at(i).second == - A.at(j).second) {
        cout << j + 1 << endl;
      }
    }
  }
}