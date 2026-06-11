#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  string s;
  cin >> n >> s;
  int cr = count(s.begin(), s.end(), 'R');
  int cb = count(s.begin(), s.end(), 'B');
  puts(cr > cb ? "Yes" : "No");
}
