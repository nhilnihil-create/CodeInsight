#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  string S, T;
  cin >> S >> T;
  map<char, char> ms, mt;

  rep(i, S.size()) {
    char s = S[i], t = T[i];
    if (ms.count(s) == 0)
      ms[s] = t;
    else if (ms[s] != t) {
      cout << "No" << endl;
      return 0;
    }

    if (mt.count(t) == 0)
      mt[t] = s;
    else if (mt[t] != s) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
}