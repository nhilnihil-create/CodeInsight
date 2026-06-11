#include <iostream>
#include <string>
#include <map>

using namespace std;

void calc(int n, int i, const string &s, map<string, int> &m) {
  string s1, s2;
  for (int j = n-1; j >= 0; --j) { 
    int mask = 1<<j;
    if (mask & i) s1 += s[j];
    else s2 += s[j]-32;
  }
  m[s1+s2] += 1;
  // cerr << s1 << " " << s2 << endl;
};

typedef long long ll;
int main() {
  int n; cin >> n;
  string s; cin >> s;
  string s1, s2;
  for (int i = 0; i < n; ++i) { 
    s1 += s[i];
    s2 += s[2*n-1-i];
  }
  map<string, int> m1, m2;
  int n2 = 1<<n;
  for (int i = 0; i < n2; ++i) { 
    calc(n, i, s1, m1);
    calc(n, i, s2, m2);
  }
  ll ans = 0;
  for (auto it : m1) {
    // cerr << it.first << " " << it.second << endl;
    auto it2 = m2.find(it.first);
    if (it2 == m2.end()) continue;
    ans += (ll)it.second*(ll)it2->second;
  }
  cout << ans << endl;
  return 0;
}
