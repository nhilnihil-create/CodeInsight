#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<double> a(N,0);
  double ave = 0;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    ave += a[i];
  }
  ave /= N;
  int ans = 0;
  for (int i = 1; i < N; i++) {
    if (abs(a[i]-ave) < abs(a[ans]-ave)) {
      ans = i;
    }
  }
  cout << ans;
}