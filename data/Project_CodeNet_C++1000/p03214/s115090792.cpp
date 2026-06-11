#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++) cin >> a.at(i);
  int sum = 0;
  for (int i = 0; i < N; i++) sum += a.at(i);
  double avg = sum / (double)N;
  double diff = 1000;
  for (int i = 0; i < N; i++) diff = min(diff, abs(avg - a.at(i)));
  for (int i = 0; i < N; i++) {
    if (abs(avg - a.at(i)) == diff) {
      cout << i << endl;
      return 0;
    }
  }
}