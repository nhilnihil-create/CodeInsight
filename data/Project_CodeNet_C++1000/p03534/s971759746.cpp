#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <array>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <utility>
#include <functional>
#include <random>

using namespace std;
using lli = long long int;
template<class T, class U> void init_n(vector<T>& v, size_t n, U x) 
{ v = vector<T>(n, x); }
template<class T> void init_n(vector<T>& v, size_t n) { init_n(v, n, T()); }
template<class T> void read_n(vector<T>& v, size_t n, size_t o = 0)
{ v = vector<T>(n+o); for (lli i=o; i<n+o; ++i) cin >> v[i]; }
template<class T> void read_n(T a[], size_t n, size_t o = 0)
{ for (lli i=o; i<n+o; ++i) cin >> a[i]; }
template<class T> T gabs(const T& x) { return max(x, -x); }
#define abs gabs

string s;
int main() {
  cin >> s;
  lli n = s.size();
  lli cnt[30], d=n%3; fill(begin(cnt), end(cnt), 0);
  for (lli i=0; i<n; ++i) {
    cnt[s[i]-'a']++;
  }
  for (lli i=0; i<=26; ++i) {
    if (cnt[i] > n/3) {
      if (cnt[i] == n/3+1 && d>0) {
        --d;
      } else {
        cout << "NO\n"; return 0;
      }
    }
  }
  cout << "YES\n";
  return 0;
}
