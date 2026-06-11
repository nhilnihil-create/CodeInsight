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

int n;

void input() {
  cin >> n;
}

void solve() {
  if (n == 1) {
    cout << "Hello World";
  } else {
    int a;
    int b;
    cin >> a >> b;

    cout << a + b;
  }
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
