#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  int values[N];
  for (int i = 0; i < N; i++) {
    cin >> values[i];
  }

  int costs[N];
  for (int i = 0; i < N; i++) {
    cin >> costs[i];
  }

  int ans = 0;
  for (int i = 0; i < N; i++) {
    int diff = values[i] - costs[i];
    if (diff > 0) {
      ans += diff;
    }
  }

  cout << ans << endl;
}