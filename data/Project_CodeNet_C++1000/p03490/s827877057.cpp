#include <bits/stdc++.h>
using namespace std;

void prians(bool answer) {
  if(answer)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
string s;
vector<int> xy[2];
int goal[2];

void make();
bool solve();

int main() {
  cin >> s >> goal[0] >> goal[1];
  goal[0] += 8000;
  goal[1] += 8000;
  make();
  prians(solve());
  return 0;
}

void make() {
  int cnt = 0, now = 0;
  for(int i = 0; i < s.size(); ++i) {
    if(s[i] == 'F') ++cnt;
    if(s[i] == 'T' || i == s.size() - 1) {
      xy[now].push_back(cnt);
      now = 1 - now;
      cnt = 0;
    }
  }
}

bool solve() {
  bitset<16005> bt[2];
  bt[0][8000 + xy[0][0]] = 1;
  bt[1][8000] = 1;
  for(int t = 0; t < 2; ++t) {
    for(int i = 0; i < xy[t].size(); ++i) {
      if(t == i && i == 0) continue;
      bt[t] = (bt[t] << xy[t][i]) | (bt[t] >> xy[t][i]);
    }
    if(!bt[t][goal[t]]) return 0;
  }
  return 1;
}