#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  int t[++N], x[N], y[N];
  t[0] = 0;
  x[0] = 0;
  y[0] = 0;
  for (int i = 1; i < N; i++) {
    cin >> t[i] >> x[i] >> y[i];
  }
  for (int i = 1; i < N; i++) {
    if (t[i]-t[i-1] < abs(x[i]-x[i-1])+abs(y[i]-y[i-1]) || (t[i]-t[i-1]-abs(x[i]-x[i-1])-abs(y[i]-y[i-1]))%2) {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
}