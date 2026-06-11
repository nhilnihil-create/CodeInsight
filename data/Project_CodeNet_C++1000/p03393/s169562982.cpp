#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1000000007;
const ll INF = 9223372036854775807;
#define Sort(a) sort(a.begin(), a.end())
#define Bsort(a) sort(a.begin(), a.end(), greater<ll>())
#define Pi acos(-1)

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  string s;
  cin >> s;
  if (s.size() < 26) {
    int a[26] = {0};
    for (int i = 0; i < s.size(); i++) {
      a[s[i] - 97] = 1;
    }
    for(int i = 0; i < 26; i++) {
      if (a[i] == 0) {
        cout << s << char(i + 97) << '\n';
        return 0;
      }
    }
  }
  else if ("zyxwvutsrqponmlkjihgfedcba" == s) {
    cout << -1 << '\n';
    return 0;
  }
  else {
    for (int i = 0; i < 25; i++) {
      char p = s[s.size()-1-i];
      char q = s[s.size()-2-i];
      char t = 'z';
      if (p > q) {
        cout << s.substr(0,24-i);
        for (int j = 0; j < i+1; j++) {
          if (char(s[25-j]) > char(s[24-i])) {
            t = min(t, char(s[25-j]));
          }
        }
        cout << t << '\n';
        return 0;
      }
    }
  }
}