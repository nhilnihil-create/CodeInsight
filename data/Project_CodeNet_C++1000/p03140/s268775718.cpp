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
  int n;
  string a, b, c;
  cin >> n >> a >> b >> c;
  int ret = 0;
  for(int i = 0; i < n; i++) {
    if(a[i] == b[i] && b[i] == c[i]) ret += 0;
    else if(a[i] == b[i] || b[i] == c[i] || a[i] == c[i]) ret += 1;
    else ret += 2;
  }
  cout << ret << endl;
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
