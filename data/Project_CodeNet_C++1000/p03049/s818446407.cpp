#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  vector<string> s(n);
  int inner = 0, enda = 0, beginb = 0, both = 0;
  for (int i = 0; i < n; i++) {
    cin >> s.at(i);
    for (int j = 0; j < s.at(i).size() - 1; j++) {
      if (s.at(i).at(j) == 'A' && s.at(i).at(j + 1) == 'B') inner++;
    }
    if (s.at(i).front() == 'B' && s.at(i).back() == 'A') both++;
    else if (s.at(i).front() == 'B') beginb++;
    else if (s.at(i).back() == 'A') enda++;
  }
  
  int joint = 0;
  if (both == 0) joint = min(beginb, enda);
  else {
    if (beginb > 0 && enda > 0) joint = both + 1 + min(beginb - 1, enda - 1);
    else if (beginb == 0 && enda == 0) joint = both - 1;
    else joint = both;
  }
  
  cout << inner + joint << '\n';
}