#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;

void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  int maxRet = min(a, b);
  int minRet = 0;
  while(a + b + minRet > n) {
    a--;
    b--;
    minRet++;
  }
  cout << maxRet << " " << minRet << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  /*
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  */
}
