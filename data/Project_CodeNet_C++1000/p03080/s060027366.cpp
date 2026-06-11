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
  string s;
  cin >> n >> s;
  int r = 0;
  int b = 0;
  for(int i = 0; i < s.size(); i++) if(s[i] == 'R') r++; else b++;
  if(r > b) cout << "Yes\n";
  else cout << "No\n";
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
