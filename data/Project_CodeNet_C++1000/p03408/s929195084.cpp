#include <iostream>
#include <map>

using namespace std;

int main() {
  int n, m;
  map<string, int> s;
  string x;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (s.find(x) == s.end()) {
      s[x] = 0;
    }
    s[x]++;
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> x;
    if (s.find(x) != s.end()) {
      s[x]--;
    }
  }
  int max = 0;
  for (map<string, int>::iterator it = s.begin(); it != s.end(); it++) {
    if (max < it->second) {
      max = it->second;
    }
  }
  cout << max << endl;

  return 0;
}
