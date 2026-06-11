#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define REP(i, n) for (int i = 0; i < (n); i++)

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);

int main() {
  string s, t;
  cin >> s;
  cin >> t;
  vector<int> S(150, 0), T(150, 0);
  REP(i, s.size()) S[int(s[i])]++;
  REP(i, t.size()) T[int(t[i])]++;
  sort(S.rbegin(), S.rend());
  sort(T.rbegin(), T.rend());
  REP(i, S.size()) {
    if (S[i] != T[i]) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;

  return 0;
}