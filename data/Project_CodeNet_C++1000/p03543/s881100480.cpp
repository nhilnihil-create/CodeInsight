#include <bits/stdc++.h>
using namespace std;

int main() {
  string N;
  cin >> N;

  string ans = "No";
  if (N[0] == N[1] && N[1] == N[2]) {
    ans = "Yes";
  }
  if (N[1] == N[2] && N[2] == N[3]) {
    ans = "Yes";
  }
  cout << ans << endl;
  return 0;
}