#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> d(N);
  for (int i = 0; i < N; i++) cin >> d.at(i);
  int count = 0, high = 0, current = 100000000000, note = 0;
  for (int i = 0; i < N; i++) {
    high = 0;
    for (int j = 0; j < N; j++) {
      if (d.at(j) > high) {
        high = d.at(j);
        note = j;
      }
    }
    d.at(note) = 0;
    if (high < current) {
      count++;
      current = high;
    }
  }
  cout << count;
}
