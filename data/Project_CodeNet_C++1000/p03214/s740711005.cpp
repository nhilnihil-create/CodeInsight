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

int l[105];
void solve() {
  int n;
  int sum = 0;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> l[i];
    sum += l[i];
  }
  int error = 1e9;
  int ret = -1;
  for(int i = 0; i < n; i++) {
    if(abs(sum - n * l[i]) < error) {
      error = abs(sum - n * l[i]);
      ret = i;
    }
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
