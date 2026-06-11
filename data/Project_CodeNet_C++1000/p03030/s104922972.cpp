#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<tuple<string, int, int>> v(n);
  
  for (int i = 0; i < n; i++) {
    string s;
    int p;
    cin >> s;
    cin >> p;
    v.at(i) = make_tuple(s, 100 - p, i + 1);
  }
  
  sort(v.begin(), v.end());
  
  for (auto p : v) {
    cout << get<2>(p) << endl;
  }
}