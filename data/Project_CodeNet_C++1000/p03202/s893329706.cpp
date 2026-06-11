#include <algorithm>
#include <bitset>
#include <cctype>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
/*----------------------------------------*/

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  // mid = 1 のとき繰り上がりの回数が非常に多くなることがある？
  bool good = true;
  REP(i, n-1) {
    if (a[i] >= a[i+1]) good = false;
  }
  if (good) {
    cout << 1 << '\n';
    return 0;
  }
  int low = 1, high = n; // (low, high]
  while (high - low > 1) {
    int mid = (low + high) / 2;
    bool ok = true;
    map<int, int> mp;
    REP(i, n-1) {
      if (a[i] >= a[i+1]) {
        mp.erase(mp.lower_bound(a[i+1]+1), mp.end());
        ++mp[a[i+1]];
        for (int j = a[i+1]; j >= 1; --j) {
          if (mp[j] < mid) break;
          if (j == 1) {
            ok = false;
            break;
          }
          mp.erase(j);
          ++mp[j-1];
        }
      }
      if (!ok) break;
    }
    if (ok) high = mid;
    else low = mid;
  }
  cout << high << '\n';
  return 0;
}
