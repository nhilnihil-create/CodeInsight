#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int half;
  cin >> half;
  string s;
  cin >> s;
  map<string,int> mp;
  for (int t = 0; t < (1 << half); t++) {
    string a = "", b = "";
    for (int i = 0; i < half; i++) {
      if (t & (1 << i)) {
        a += s[i];
      } else {
        b += s[i];
      }
    }
    string c = a + "." + string(b.rbegin(), b.rend());
    // cout<<c<<endl;
    mp[c]++;
  }
  long long ans = 0;
  for (int t = 0; t < (1 << half); t++) {
    string a = "", b = "";
    for (int i = 0; i < half; i++) {
      if (t & (1 << i)) {
        a += s[i + half];
      } else {
        b += s[i + half];
      }
    }
    string c = string(b.rbegin(), b.rend()) + "." + a;
    ans += mp[c];
  }
  cout << ans << '\n';
  return 0;
}