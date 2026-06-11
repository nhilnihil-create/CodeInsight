#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> x(N + 1);
  cin >> x.at(N);
  for (int i = 0; i < N; i++) {
    cin >> x.at(i);
  }
  sort (x.begin(), x.end());
  int ans = x.at(1) - x.at(0);
  for (int i = 1; i < N; i++) { 
    int memo = x.at(i + 1) - x.at(i);
    ans = gcd(ans, memo);
  }
  cout << ans << endl;
}