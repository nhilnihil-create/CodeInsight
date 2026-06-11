#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<tuple<string, int, int>> a;
  for(int i = 0; i < n; i++) {
    string s;
    int p;
    cin >> s >> p;
    a.push_back(make_tuple(s, 100-p, i));
  }
  sort(a.begin(), a.end());
  for(int i = 0; i < n; i++) {
    int x;
    tie(ignore, ignore, x) = a.at(i);
    cout << x+1 << endl;
  }
  
  return 0;
}