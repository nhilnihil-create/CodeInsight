/*
 * atcoder/abc089/b.cpp
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
void solve();
int main() { solve(); return 0; }

#define ld long double
void solve() {
  vector<string> S(3);
  loop(i,0,3) cin >> S[i];
  cout << S[0][0] << S[1][1] << S[2][2] << endl;
}
