#include <bits/stdc++.h>
using namespace std;

bool pal(string s) {
  string t = s;
  reverse(t.begin(), t.end());
  return s == t;
}

int main() {
  string S;
  cin >> S;
  
  string T = S;
  T = regex_replace(T, regex("x"), "");
  
  if (!pal(T)) return cout << -1 << "\n", 0;

  int N = T.size() + 1;

  vector<int> V(N);

  for (int i = 0, it = 0; i < S.size(); i++) {
    if (S.at(i) == 'x') V.at(it)++;
    else it++;
  }

  int ans = 0;
  for (int i = 0; i < N / 2; i++) {
    int j = N - i - 1;
    ans += abs(V.at(i) - V.at(j));
  }
  cout << ans << "\n";
}