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
  int a, b, k;
  cin >> a >> b >> k;
  for(int i = 0; i < k; i++) {
    int& from = (i%2==0 ? a : b);
    int& to = (i%2==1 ? a : b);
    if(from%2) from--;
    to += from/2;
    from /= 2;
  }
  cout << a << " " << b << endl;
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
