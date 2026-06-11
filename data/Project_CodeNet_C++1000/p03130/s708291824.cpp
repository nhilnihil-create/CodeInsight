#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  vector<int> t(3, 0);
  REP(i, 3) {
    int a, b;
    cin >> a >> b;
    t[a - 1]++;
    t[b - 1]++;
  }
  if(max({t[0], t[1], t[2], t[3]}) <= 2)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}