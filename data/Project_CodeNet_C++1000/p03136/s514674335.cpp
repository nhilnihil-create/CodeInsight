#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int sum = 0, ma = 0;
  for (int i = 0; i < N; ++i) {
    int a;
    cin >> a;
    sum += a;
    ma = max(ma, a);
  }
  if (sum - ma > ma) cout << "Yes" << endl;
  else cout << "No" << endl;
}