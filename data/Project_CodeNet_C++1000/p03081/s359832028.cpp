#include <bits/stdc++.h>

using namespace std;

int simulate(vector<pair<char, char>> &qs, string &s, int pos) {
  for (int i = 0; i < qs.size(); ++i) {
    if (s[pos] != qs[i].first) {
      continue;
    }

    if (qs[i].second == 'L') {
      pos--;
    } else {
      pos++;
    }

    if (pos < 0) {
      return -1;
    } else if (pos >= s.size()) {
      return 1;
    }
  }

  return 0;
}

int main(int argc, const char *argv[]) {
  int n, q;
  string s;
  cin >> n >> q >> s;

  vector<pair<char, char>> qs(q);
  for (auto &p : qs) {
    cin >> p.first >> p.second;
  }

  // solve left
  int ans_l, ans_r;
  {
    int left = 0, right = s.size();
    while (left < right) {
      int mid = (left + right) / 2;
      int sim = simulate(qs, s, mid);
      if (sim == -1) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    ans_l = right;
  }

  // solve right
  {
    int left = 0, right = s.size();
    while (left < right) {
      int mid = (left + right) / 2;
      int sim = simulate(qs, s, mid);
      if (sim == 1) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    ans_r = right;
  }

  int dropped = 0;
  dropped += ans_l;
  dropped += s.size() - ans_r;

  cout << s.size() - dropped << '\n';
}