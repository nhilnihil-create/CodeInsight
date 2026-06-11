
// Problem : A - B +/- A
// Contest : AtCoder Beginner Contest 118
// URL : https://atcoder.jp/contests/abc118/tasks/abc118_a
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <set>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
typedef long double ld;

constexpr int INF = 1e9;
constexpr ll BIGINF = 1e18;
constexpr double EPS = 1e-16;
constexpr int MOD = 1e9 + 7;

void preambule() {
  cin.tie(0);
  cout.precision(16);
  cout << fixed;
}

int a;
int b;

void input() {
  cin >> a >> b;
}

void solve() {
  int ans = b - a;
  
  if (b % a == 0)
    ans = a + b;
    
  cout << ans << '\n';
}

int main() {
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  preambule();
  input();
  solve();
}
