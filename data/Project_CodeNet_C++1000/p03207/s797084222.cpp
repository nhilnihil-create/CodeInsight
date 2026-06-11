#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int sum = 0, ma = 0;
  for (int i = 0; i < N; ++i) {
    int p; cin >> p;
    sum += p;
    ma = max(ma, p);
  }
  cout << sum - ma/2 << endl;
}