#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<string> rows(3);
  for (int i = 0; i < 3; i++)
    cin >> rows[i];
  string res;
  for (int i = 0; i < 3; i++)
    res += rows[i][i];
  cout << res << '\n';   
  return 0;
}