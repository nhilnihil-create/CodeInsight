#include <bits/stdc++.h>
#include <vector>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  string s;
  cin >> s;
  int ans = count(s.begin(), s.end(), '1');
  cout << ans << '\n';
}