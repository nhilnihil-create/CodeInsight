#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++) cin >> a.at(i);
  int high = 0, note = 0, Alice = 0, Bob = 0;
  for (int i = 0; i < N; i += 2) {
    for (int j = 0; j < N; j++) {
      if (a.at(j) > high) {
        high = a.at(j);
        note = j;
      }
    }
    Alice += high;
    a.at(note) = 0;
    high = 0;
    for (int j = 0; j < N; j++) {
      if (a.at(j) > high) {
        high = a.at(j);
        note = j;
      }
    }
    Bob += high;
    a.at(note) = 0;
    high = 0;
  }
  cout << Alice - Bob;
}
