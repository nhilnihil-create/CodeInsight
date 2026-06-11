#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int n;
  cin >> n;

  unordered_map<string, int> count;

  for (int i = 0; i < n; ++i) {
    string s; cin >> s;
    count[s]++;
  }

  int m;
  cin >> m;

  for (int i = 0; i < m; ++i) {
    string s; cin >> s;
    count[s]--;
  }

  int res = 0;
  for (auto p: count) {
    res = max(res, p.second);
  }

  cout << res << "\n";
}
