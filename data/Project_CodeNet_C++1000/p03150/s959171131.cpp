#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define contains(v, t) (find(v.begin(), v.end(), t) != v.end())
#define MOD 1000000007
typedef long long ll;
typedef unsigned long long ull;

int main() {
  string s;
  cin >> s;

  for (int i = 0; i < s.length(); i++) {
    for (int j = i; j < s.length(); j++) {
      string frag = s.substr(0, i) + s.substr(j, s.length());
      if (frag == "keyence") {
        cout << "YES";
        return 0;
      }
    }
  }
  cout << "NO";
}