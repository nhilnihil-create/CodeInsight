#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> s(N);

  for (int i = 0; i < N; i++) {
    cin >> s.at(i);
  }

  int M;
  cin >> M;
  vector<string> t(M);

  for (int i = 0; i < M; i++) {
    cin >> t.at(i);
  }

  int maximum_amount = 0;
  for (int i = 0; i < N; i++) {
    string word = s.at(i);
    int amount = 0;

    // blue
    for (int j = 0; j < N; j++) {
      if (word == s.at(j)) {
        amount++;
      }
    }
    // red
    for (int j = 0; j < M; j++) {
      if (word == t.at(j)) {
        amount--;
      }
    }

    if (amount > maximum_amount) {
      maximum_amount = amount;
    }
  }

  cout << maximum_amount << endl;
}