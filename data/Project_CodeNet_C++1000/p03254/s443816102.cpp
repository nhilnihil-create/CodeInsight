#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  int64_t x;
  cin >> N >> x;
  vector<int64_t> vec(N);
  for (int i = 0; i < N; i++) {
    cin >> vec.at(i);
  }
  sort(vec.begin(), vec.end());
  int count = 0;

  for (int i = 0; i < N; i++) {
    if (i == N - 1 && x - vec[i] > 0) {
      break;
    }
    if (x - vec[i] >= 0) {
      x -= vec[i];
      count++;
    } else {
      break;
    }
  }

  cout << count << endl;
}