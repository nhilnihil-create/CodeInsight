#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <bitset>
#include <cstring>
#include <deque>
#include <iomanip>
#include <limits>
#include <fstream>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define MOD1 1000000007



int main() {
  ll A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  ll ans = 1000000000;

  for (ll i = 0; i <= max(X, Y); i++) {
    ll x, y;
    X - i >= 0 ? x = X - i : x = 0;
    Y - i >= 0 ? y = Y - i : y = 0;
    ans = min(ans, A * x + B * y + C * 2 * i);
  }

  cout << ans << endl;


}
