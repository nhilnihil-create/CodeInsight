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

int n, q;
string s;
char desire[200005];
char dir[200005];
bool valid[200005];
void solve() {
  // TODO: fix input
  cin >> n >> q >> s;
  for(int i = 0; i < q; i++) {
    cin.ignore();
    cin >> desire[i] >> dir[i];
  }
  {
    // prefix
    int lhs = -1;
    int rhs = n-1;
    while(lhs != rhs) {
      int mid = (lhs+rhs+1)/2;
      int curr = mid;
      for(int i = 0; i < q && curr >= 0 && curr < n; i++) {
        if(desire[i] == s[curr]) {
          if(dir[i] == 'L') curr--;
          else curr++;
        }
      }
      if(curr < 0) lhs = mid;
      else rhs = mid-1;
    }
    for(int i = 0; i <= lhs; i++) {
      valid[i] = true;
    }
  }
  {
    // suffix
    int lhs = 0;
    int rhs = n;
    while(lhs != rhs) {
      int mid = (lhs+rhs)/2;
      int curr = mid;
      for(int i = 0; i < q && curr >= 0 && curr < n; i++) {
        if(desire[i] == s[curr]) {
          if(dir[i] == 'L') curr--;
          else curr++;
        }
      }
      if(curr >= n) rhs = mid;
      else lhs = mid+1;
    }
    for(int i = lhs; i < n; i++) {
      valid[i] = true;
    }
  }
  int ret = 0;
  for(int i = 0; i < n; i++) {
    ret += valid[i];
  }
  cout << n - ret << "\n";
}

void casesolve() {
  int t;
  cin >> t;
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
