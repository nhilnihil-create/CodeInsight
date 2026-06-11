#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
  string s;
  cin >> s;
  if (s == "zyxwvutsrqponmlkjihgfedcba") {
    cout << - 1 << endl;
    return 0;
  }
  if (s.size() < 26) {
    string t = s;
    sort(t.begin(), t.end());
    rep(i,26) {
      if (t[i] != 'a'+i) {s += char('a'+i); break;}
    }
    cout << s << endl;
  } else {
    string t = s;
    next_permutation(t.begin(), t.end());
    rep(i,26) {
      if (s[i] != t[i]) {cout << t[i] << endl; break;}
      cout << t[i];
    }
  }
   
  
  return 0;
}