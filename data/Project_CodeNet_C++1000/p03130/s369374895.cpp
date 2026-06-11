#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define ALL(v) (v).begin(), (v).end()

using namespace std;
using ll = long long;

int main()
{
  int cnt[5] = {};
  REP(i, 6) {
    int a; cin >> a;
    cnt[a]++;
  }

  for (int i = 1; i <= 4; ++i) {
    if (cnt[i] > 2) {
      cout << "NO" << endl;;
      return 0;
    }
  }
  cout << "YES" << endl;
}