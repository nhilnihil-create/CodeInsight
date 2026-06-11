#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int x, y;
  cin >> x >> y;
  int i = 0;
  while (i <= s.size()) {
    if (i == s.size() || s[i] == 'T') {
      x -= i;
      break;
    }
    i++;
  }
  vector<int> dist[2];
  int idx = 0;
  int cur_dist = 0;
  while (i < s.size()) {
    if (s[i] == 'T') {
      if (cur_dist != 0) {
        dist[idx].push_back(cur_dist);
      }
      idx = 1 - idx;
      cur_dist = 0;
    } else {
      cur_dist++;
    }
    i++;
  }
  if (cur_dist != 0) {
    dist[idx].push_back(cur_dist);
  }
  bool feasible = true;
  for (int j = 0; j < 2; j++) {
    vector<bool> possible(16001, false);
    possible[0 + 8000] = true;
    for (int k = 0; k < dist[j].size(); k++) {
      vector<bool> possible2(16001, false);
      int offset = dist[j][k];
      for (int l = -8000; l <= 8000; l++) {
        if (possible[l + 8000]) {
          if (l - offset >= -8000) {
            possible2[l - offset + 8000] = true;
          }
          if (l + offset <= 8000) {
            possible2[l + offset + 8000] = true;
          }
        }
      }
      possible = possible2;
    }
    if (j == 0 && (x < -8000 || x > 8000 || !possible[x + 8000])) feasible = false;
    if (j == 1 && !possible[y + 8000]) feasible = false;
  }
  if (feasible) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}