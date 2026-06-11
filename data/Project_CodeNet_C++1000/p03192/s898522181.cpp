#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
  int N;
  cin >> N;

  int ans = 0;
  for (int i = 0; i < 4; i++) {
    if (N % 10 == 2) ans++;
    N /= 10;
  }

  cout << ans << endl;
}