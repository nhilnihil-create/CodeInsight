#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  for(int i = 0; i < N; i++) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  
  int alice = 0;
  int bob = 0;

  if (N % 2 == 0) {
    for (int i = 0; i < N / 2; i++) {
      alice += a[2 * i];
      bob += a[2 * i + 1];
    }
  cout << alice - bob << endl;
  }

  else {
    for (int i = 0; i < N / 2; i++) {
      alice += a[2 * i];
      bob += a[2 * i + 1];
    }
  cout << alice + a[N - 1] - bob << endl;
  }
}