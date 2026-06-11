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
typedef pair<ll, int> query;
typedef vector<vector<ll>> matrix;

int n;
int lhs[100005];
int rhs[100005];
void solve() {
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> lhs[i] >> rhs[i];
  }
  sort(lhs, lhs+n+1);
  sort(rhs, rhs+n+1);
  ll ret = 0;
  ll curr = 0;
  for(int i = 0; i <= n; i++) {
    curr += lhs[n-i];
    curr -= rhs[i];
    ret = max(ret, curr);
  }
  cout << 2*ret << "\n";
}

void casesolve() {
  int t;
  cin >> t; cin.ignore();
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  // casesolve();
}
