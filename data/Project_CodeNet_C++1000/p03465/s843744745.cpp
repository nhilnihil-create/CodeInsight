#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef bitset<4000005> bs;

bs dp;
void solve() {
  int n;
  cin >> n;
  int tot = 0;
  dp.set(0);
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    tot += x;
    dp |= (dp << x);
  }
  int ret = (tot+1)/2;
  while(!dp[ret]) ret++;
  cout << ret << "\n";
}

void casesolve() {
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << " ";
    solve();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  // casesolve();
}
