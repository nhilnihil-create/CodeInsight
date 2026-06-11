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
  int zero = 0, one = 0;
  rep(i, s.length()) {
    if (s[i] == '0') zero++;
    else one++;
  }
  cout << s.length() - (max(zero, one) - min(zero, one)) << endl;
}
