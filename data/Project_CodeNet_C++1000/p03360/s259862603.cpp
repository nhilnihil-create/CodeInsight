#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

using namespace std;

int main() {
  int a, b, c, k;
  cin >> a >> b >> c >> k;
  vector<int> array = {a, b, c};

  sort(array.begin(), array.end());
  REP(i, k) array[2] *= 2;
  cout << array[0] + array[1] + array[2] << "\n";

  return(0);
}
