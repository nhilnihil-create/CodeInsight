#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<tuple<string, int, int>> p(N);
  for (int i = 0; i < N; i++) {
    string s;
    int r;
    cin >> s >> r;
    p.at(i) = make_tuple(s, -r, i+1);
  }
  
  sort(p.begin(), p.end());
  
  for (tuple<string, int, int> t : p) {
    string s;
    int u, v;
    tie(s, u, v) = t;
    cout << v << endl;
  }
}