#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, x, sweets[100], counter = 0;
  cin >> N >> x;
  for (int i = 0; i < N; i++) cin >> sweets[i];
  sort(sweets, sweets + N);

  for (int i = 0; i < N; i++) {
    if ((x - sweets[i] < 0) || (i == N - 1 && x != sweets[i])) {
      break;
    }

    x -= sweets[i];
    counter++;
  }

  cout << counter << endl;
}
