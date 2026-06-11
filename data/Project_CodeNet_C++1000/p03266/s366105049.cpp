/*
 * atcoder/abc108_2nd/c.cpp
 */

// C++ 14
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring> // memset
#include <cassert>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
template <class T> bool chmin(T &a, T b) { if (a > b) {a = b; return true; } return false; }
template <class T> bool chmax(T &a, T b) { if (a < b) {a = b; return true; } return false; }

/*
 * aを決める
 * a % K = 0の場合)  a + b, a + cよりb % K, c % Kである必要がある
 * a % K != 0の場合) b = K - a, c = K - a
 */
int N, K;
ll counter[200100] = {0};
void solve() {
  cin >> N >> K;
  loop(a,1,N+1) {
    counter[a%K]++;
  }

  ll count = 0;
  loop(a,0,K) {
    int bK = ((K-a)+K)%K;
    int cK = ((K-a)+K)%K;
    count += ((bK+cK)%K == 0) * counter[a] * counter[bK] * counter[cK];
  }
  cout << count << endl;
}
int main() {
  // cout.precision(15); cout << fixed;

  solve();

  return 0;
}
