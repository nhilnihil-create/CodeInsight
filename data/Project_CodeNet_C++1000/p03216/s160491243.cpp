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
typedef pair<int, pii> pipii;

string s;
int n;

void realsolve() {
  int k;
  cin >> k;
  ll ret = 0;
  ll d = 0;
  ll m = 0;
  ll c = 0;
  ll dm = 0;
  ll mc = 0;
  for(int i = 0; i < n; i++) {
    if(i >= k) {
      if(s[i-k] == 'D') {
        dm -= m;
        d--;
      }
      else if(s[i-k] == 'M') {
        mc -= c;
        m--;
      }
      else if(s[i-k] == 'C') {
        c--;
      }
    }
    if(s[i] == 'D') {
      d++;
    }
    else if(s[i] == 'M') {
      dm += d;
      m++;
    }
    else if(s[i] == 'C') {
      ret += dm;
      mc += m;
    }
  }
  cout << ret << "\n";
}

void solve() {
  cin >> n >> s;
  int qq;
  cin >> qq;
  while(qq--) realsolve();
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
