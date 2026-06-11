#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
  int N;
  cin >> N;
  vector<int> t(N + 1), x(N + 1), y(N + 1);
  t[0] = x[0] = y[0] = 0;
  for (int i = 1; i <= N; i++) {
    cin >> t[i] >> x[i] >> y[i];
  }
 
  for (int i = 0; i < N; i++) {
    int l1_dist = abs(x[i + 1] - x[i]) + abs(y[i + 1] - y[i]);
    int intarval = t[i + 1] - t[i];
    if (l1_dist > intarval || (intarval - l1_dist) % 2 != 0) {
      cout << "No" << endl;
      return 0;
    }
  }
 
  cout << "Yes" << endl;
 
  return 0;
}