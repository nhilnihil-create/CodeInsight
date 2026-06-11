#include <bits/stdc++.h>
using namespace std;

int main () {
  int N, K;
  cin >> N >>K;
  int ans = 0;
  if (N%K == 0) {
    ans = 0;
  } else {
    ans = 1;
  }
  cout << ans << endl;
}