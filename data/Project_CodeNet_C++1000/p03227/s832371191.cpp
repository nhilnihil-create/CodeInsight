#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define ALL(v) (v).begin(), (v).end()

using namespace std;
using ll = long long;

int main()
{
  string s; cin >> s;
  if (s.size() == 2) {
    cout << s << endl;
  } else if (s.size() == 3) {
    reverse(ALL(s));
    cout << s << endl;
  }
}