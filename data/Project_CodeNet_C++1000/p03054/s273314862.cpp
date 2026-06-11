#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cassert>
#include <cfloat>
#include <complex>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;
typedef deque<ll> dqll;

#define MOD 1000000007

ll N, sr, sc;
string S, T;

bool test(char u, char l, ll x, ll pos) {
  ll tmp = x;
  for (int i = N - 1; i >= 0; i--) {
    if (T[i] == l) tmp++;
    tmp = min(tmp, x);    
    if (S[i] == u) tmp--;
    if (tmp == 0) return true;
  }
  if (tmp < pos) return true;

  tmp = 1;
  for (int i = N - 1; i >= 0; i--) {
    if (T[i] == u) tmp--;
    tmp = max(tmp, 1LL);    
    if (S[i] == l) tmp++;
    if (tmp == x + 1) return true;
  }
  if (tmp > pos) return true;

  return false;
}  // test

int main() {
  ll H, W;
  cin >> H >> W >> N >> sr >> sc >> S >> T;

  if (test('D', 'U', H, sr) || test('R', 'L', W, sc))
    puts("NO");
  else
    puts("YES");

  return 0;
}
