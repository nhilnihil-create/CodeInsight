#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> d(N);
  for (int i = 0; i < N; i++) cin >> d[i];

  sort(d.begin(), d.end());

  int count = 0;
  int old = 0;
  for (int t : d) {
    if (old < t) {
      count++;
      old = t;
    }
  }

  cout << count << endl;
}