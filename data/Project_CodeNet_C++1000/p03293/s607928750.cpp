#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define contains(v, t) (find(v.begin(), v.end(), t) != v.end())
#define MOD 1000000007
using ll = long long;
using ull = unsigned long long;

int main() {
  string s,t;
  cin>>s>>t;
  rep(i, s.length()) {
    s = s[s.length() - 1] + s.substr(0, s.length() - 1);
    if (s == t) {
      cout << "Yes";
      return 0;
    }
  }
  cout << "No";
}
