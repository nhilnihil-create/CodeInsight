#include <bits/stdc++.h>
using namespace std;
string s, t;
int in[26], out[26], vis[26][26];
int main() {
  cin >> s >> t;
  for (int i = 0; i < s.size(); i++) {
    if (!vis[s[i] - 'a'][t[i] - 'a']) in[s[i] - 'a']++, out[t[i] - 'a']++, vis[s[i] - 'a'][t[i] - 'a'] = 1;
  }
  int ok = 1;
  for (int i = 0; i < 26; i++) if (in[i] > 1 || out[i] > 1) ok = 0;
  if (ok) printf("Yes\n");
  else printf("No\n");
}
