#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>

using namespace std;

bool is_palindrome(const string &s) {
  bool res = true;
  for (int i = 0; i < s.size() / 2; i++) {
    if (s[i] != s[s.size() - i - 1]) {
      res = false;
      break;
    }
  }

  return res;
}

int solve(string &s, int l, int r) {
  if (l >= r) {
    return 0;
  }

  char l_ch = s[l], r_ch = s[r];
  if (l_ch == r_ch) {
    return solve(s, l + 1, r - 1);
  } else if (l_ch != 'x') {
    return solve(s, l, r - 1) + 1;
  } else {
    return solve(s, l + 1, r) + 1;
  }
}

int main(int argc, const char *argv[]) {
  string s;
  cin >> s;

  string s2;
  copy_if(s.begin(), s.end(), back_inserter(s2),
          [](char ch) { return ch != 'x'; });
  if (!is_palindrome(s2)) {
    cout << -1 << '\n';
    return 0;
  }

  cout << solve(s, 0, s.size() - 1) << '\n';
  return 0;
}