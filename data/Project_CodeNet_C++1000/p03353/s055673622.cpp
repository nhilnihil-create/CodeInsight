#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  string s;
  int K;
  cin >> s >> K;

  map<string, int> m;
  for (int i = 0; i < s.size(); ++i) {
    for (int j = 1; j <= 5; ++j) {
      string temp = s.substr(i, j);
      m[temp] = 1;
    }
  }

  int count = 1;
  for (auto const& entry : m) {
    if (count == K) {
      cout << entry.first << endl;
      break;
    }
    count++;
  }
  
  return 0;
}
