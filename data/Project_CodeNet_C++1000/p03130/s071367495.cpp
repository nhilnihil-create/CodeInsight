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

int deg[10];

void solve() {
  string s = "YES";
  for(int i = 0; i < 3; i++) {
    int a, b;
    cin >> a >> b;
    if(++deg[a] >= 3) {
      s = "NO";
    }
    if(++deg[b] >= 3) {
      s = "NO";
    }
  }
  cout << s << endl;
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
