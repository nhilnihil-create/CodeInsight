#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int n,m;
  int ans = 0;
  cin >> n >> m;
  ans += 1900*m + 100*(n-m);
  ans *= pow(2,m);
  cout << ans << endl;

}