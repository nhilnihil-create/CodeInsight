#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0;i < (int)(n);i++)

int main() {
  int n, p;
  string s;
  cin >> n;
  map<string, map<int, int>> m;
  rep(i, n) {
    cin >> s >> p;
    m[s][100-p] = i+1;
  }
  for(auto pr : m) for(auto x : pr.second) cout << x.second << endl;
}