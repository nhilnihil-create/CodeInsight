#include <bits/stdc++.h>

using namespace std;

typedef pair<string, string> key;

int n;
string s;

int main()
{
  cin >> n >> s;

  map<key, int> m1;
  map<key, int> m2;
  for (int subset = 0; subset <= (1 << n) - 1; subset++) {
    string s11, s12, s21, s22;
    for (int i = 0; i < n; i++) {
      if (subset & (1 << i)) {
        s11.push_back(s[i]);
        s21.push_back(s[2*n-i-1]);
      } else {
        s12.push_back(s[i]);
        s22.push_back(s[2*n-i-1]);
      }
    }
    m1[make_pair(s11, s12)]++;
    m2[make_pair(s21, s22)]++;
  }

  uint64_t count = 0;
  for (auto p : m1) {
    if (m2.find(p.first) != m2.end()) {
      count += 1LL * p.second * m2[p.first];
    }
  }
  cout << count << endl;

  return 0;
}
